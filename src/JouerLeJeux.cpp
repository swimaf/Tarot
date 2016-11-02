#include "JouerLeJeux.h"
#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include "Distribuer.h"
#include "Pli.h"
#include "Constantes.h"


JouerLeJeux::JouerLeJeux(shared_ptr<Partie> partie) : Etat(partie)
{

}

void JouerLeJeux::demarrer() {
    cerr << "###################### JOUER LE JEUX ##############" << endl;

    int nbDeTour = partie->getJoueurs()[0]->getJeux().size();
    int nbJoueurs = partie->getJoueurs().size();
    int vainqueur = 0;

    for(int i=0; i< nbDeTour;  i++) {
        cerr << "###################### JEUX " << i <<" ##############" << endl;
        Pli pli;

        for(shared_ptr<Joueur> joueur : partie->getJoueurs()) {
            shared_ptr<ACarte> carte = joueur->selectionCarteAJouer(&pli, &partie);
            /** A REDEFINIR **/
            if(carte != NULL) {
                if(nbJoueurs == 5 && carte->operator ==(partie->getRoiAppele().get())) {
                    cerr << "REUNIFICATION EQUIPE" <<endl;
                    partie->reunirEquipe(joueur);
                }
                pli.ajouterCarte(partie->getJoueurs().indexOf(joueur), carte);
                joueur->removeCarte(carte);
                cerr << "Carte joué : " << carte->afficher() << endl;
            }

        }
        shared_ptr<ACarte> excuse = NULL;
        vainqueur = pli.indexOfVainqueur();
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
        partie->getPaquet()->ajouterCartes(pli.getCartes());

        for(shared_ptr<Equipe> equipe: partie->getEquipes()) {
            cerr << equipe->getPoints() <<  endl;
        }
    }

    cerr << "\n\n #### COMPTER LES POINTS ### \n\n";
    cerr << "Preneur equipe nb bout :" << partie->getEquipeByJoueur(partie->getPreneur())->getNbBouts() << endl;

    partie->compterPoint();
    int i = 0;

    for(shared_ptr<Joueur> joueur : partie->getClassement()->getClassement()) {
        cerr << i << "- "+joueur->getNom() << " avec " << joueur->getPoints() << endl;
        i++;
    }

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


