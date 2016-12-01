#include "CreationChien.h"
#include <QCoreApplication>
#include <iostream>
#include "JouerLeJeux.h"

CreationChien::CreationChien(shared_ptr<Partie> partie) : Etat(partie)
{

}

void CreationChien::demarrer() {
    cerr << "###################### CREATION DU CHIEN ##############" << endl;
    int tailleChien = partie->getChien()->getCartes().size();
    //partie->getFenetre()->getHumain()->ajouterCarte(partie->getChien()->getCartes()[0]);


    cerr << "\nLE CHIEN :\n";
    for(shared_ptr<ACarte> carte:partie->getChien()->getCartes()) {
        cerr << carte->afficher() << endl;
        partie->getPreneur()->ajouterCarte(carte);
    }
    partie->getChien()->montrerChien();
    partie->getChien()->clearCartes(false);

    for(shared_ptr<Joueur> joueur:partie->getJoueurs()){
        joueur->trierJeux();
    }

    if(!partie->getPreneur()->isHumain()) {
        partie->getChien()->setCartes(partie->getPreneur()->selectionCartesChien(tailleChien));
        partie->getFenetre()->setVisibleContinuer(true);
    } else {
        partie->getPreneur()->selectionCartesChien(tailleChien);
    }
}


void CreationChien::demarrerHumain(int indexCarte) {
    shared_ptr<Joueur> joueur = partie->getFenetre()->getHumain();
    if(joueur == partie->getPreneur()) {
        QWidget *button = joueur->getEmplacement()->itemAt(indexCarte)->widget();

        if(button->styleSheet().contains("margin-bottom:50px;")) {
            QString style = button->styleSheet().replace("margin-bottom:50px;", "margin-bottom:0px;");
            button->setStyleSheet(style);
            partie->getChien()->removeCarte(joueur->getJeux()[indexCarte]);
        } else {
            if(partie->getChien()->getCartes().size() != partie->getChien()->getTaille()) {
                button->setStyleSheet(button->styleSheet()+QString::fromStdString("margin-bottom:50px;"));
                partie->getChien()->ajouterCarte(joueur->getJeux()[indexCarte]);
                if(partie->getChien()->getCartes().size() == partie->getChien()->getTaille()) {
                    partie->getFenetre()->setVisibleValider(true);
                }
            }

        }
    }
}

void CreationChien::continuer() {
    transition();
}

void CreationChien::transition() {
    double points = 0;
    for(shared_ptr<ACarte> carte:partie->getChien()->getCartes()) {
       partie->getPreneur()->removeCarte(carte);
       partie->getPaquet()->ajouterCarte(carte);
       points += carte->getValeur();
    }

    partie->getEquipeByJoueur(partie->getPreneur())->ajouterPoints(points);

    cerr << "REMPLACER PAR :" << endl;
    for(shared_ptr<ACarte> carte:partie->getChien()->getCartes()) {
        cerr << carte->afficher() << endl;
    }
    partie->getChien()->clearCartes(true);

    partie->setEtat(make_shared<JouerLeJeux>(partie));
    partie->demarrer();
}


