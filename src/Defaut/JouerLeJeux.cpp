#include "JouerLeJeux.h"
#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include "Distribuer.h"
#include "Pli.h"
#include "Constantes.h"


JouerLeJeux::JouerLeJeux(shared_ptr<Partie> partie) : Etat(partie)
{
    tour = partie->getJoueurs()[0]->getJeux().size();
    joueurCourant =  0;
}


void JouerLeJeux::demarrer() {
    shared_ptr<Joueur> joueur = partie->getJoueurs()[joueurCourant];
    joueur->selectionCarteAJouer(&pli, &partie);
    if(!joueur->isHumain()) {
        //Sleeper::sleep(1);
        nextJoueur();
    }
}

void JouerLeJeux::demarrerHumain(int indexCarte) {
    shared_ptr<Joueur> joueur = partie->getFenetre()->getHumain();
    if(partie->getJoueurs()[joueurCourant] == joueur) {
        shared_ptr<ACarte> carte = joueur->getJeux()[indexCarte];
        if(joueur->getSelectable().contains(carte)) {
            joueur->removeSelectable();
            partie->setCarteSelectionne(carte);
            joueur->jouerCarte(carte);
            nextJoueur();
        }
    }

}

void JouerLeJeux::nextJoueur() {
    int nbJoueurs = partie->getJoueurs().size();
    shared_ptr<Joueur> joueur = partie->getJoueurs()[joueurCourant];

    if(nbJoueurs == 5 && partie->getCarteSelectionne()->operator ==(partie->getRoiAppele().get())) {
        cerr << "REUNIFICATION EQUIPE" <<endl;
        partie->reunirEquipe(joueur);
    }
    pli.ajouterCarte(partie->getJoueurs().indexOf(joueur), partie->getCarteSelectionne());
    joueur->removeCarte(partie->getCarteSelectionne(), false);

    cerr << "Carte joué : " << partie->getCarteSelectionne()->afficher() << endl;
    joueurCourant++;


    if(joueurCourant == partie->getJoueurs().size()) {
        shared_ptr<ACarte> excuse = NULL;
        int vainqueur = pli.indexOfVainqueur();
        cerr << "Vainqueur : "  << partie->getJoueurs()[vainqueur]->getNom() << endl;
        shared_ptr<Equipe> equipe = partie->getEquipeByJoueur(partie->getJoueurs()[vainqueur]);
        equipe->ajouterBout(nbDeBout(pli, &excuse));
        equipe->ajouterPoints(pli.getPoints());

        if(!(excuse == NULL)) {
            cerr << "TEST EXCUSE" << endl;
            shared_ptr<Equipe> equipeExcuse = partie->getEquipeByJoueur(partie->getJoueurs()[pli.getJoueurByCarte(excuse)]);
            if(equipeExcuse->getJoueurs().indexOf(partie->getJoueurs()[vainqueur]) < 0 ) {
                equipeExcuse->ajouterBout(1);
                equipeExcuse->ajouterPoints(excuse->getValeur());
                equipe->ajouterPoints(-(excuse->getValeur()+0.5));
            } else {
                equipe->ajouterBout(1);
            }
        }

        partie->couperJoueur(vainqueur);
        joueurCourant = 0;
        partie->getPaquet()->ajouterCartes(pli.getCartes());

        for(shared_ptr<Equipe> equipe: partie->getEquipes()) {
            cerr << equipe->getPoints() <<  endl;
        }
        tour--;

        if(tour == 0) {
            transition();
        } else {
            partie->getFenetre()->setVisibleContinuer(true);
        }
    } else {
        demarrer();
    }
}

void JouerLeJeux::continuer() {
    resetPli();
    demarrer();
}

void JouerLeJeux::resetPli() {
    pli.clear();
    for(shared_ptr<Joueur> joueur:partie->getJoueurs()) {
        joueur->resetEmplacement();
    }

}

void JouerLeJeux::transition() {
    resetPli();
    cerr << "Preneur equipe nb bout :" << partie->getEquipeByJoueur(partie->getPreneur())->getNbBouts() << endl;
    partie->compterPoint();
    int i = 0;
    for(shared_ptr<Joueur> joueur : partie->getClassement()->getClassement()) {
        cerr << i << "- "+joueur->getNom() << " avec " << joueur->getPoints() << endl;
        i++;
    }
    partie->getClassement()->show();
    partie->setEtat(make_shared<Distribuer>(partie));
}

int JouerLeJeux::nbDeBout(Pli pli, shared_ptr<ACarte> *excuse) {
    int i=0;
    for(shared_ptr<ACarte> carte : pli.getCartes()) {
        /** SI EXCUSE METTRE **/
        if(carte->isBout()) {
            if(carte->getType().compare("Excuse") == 0) {
                *excuse = carte;
            } else {
                ++i;
            }
        }
    }
    return i;
}


