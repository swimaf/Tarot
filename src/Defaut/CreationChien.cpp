#include "CreationChien.h"
#include <QCoreApplication>
#include <iostream>
#include "JouerLeJeux.h"

CreationChien::CreationChien(shared_ptr<Partie> partie) : Etat(partie)
{

}

void CreationChien::demarrer() {
    int tailleChien = partie->getChien()->getCartes().size();

    for(shared_ptr<ACarte> carte:partie->getChien()->getCartes()) {
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
            partie->getFenetre()->setVisibleValider(false);
        } else {
            shared_ptr<ACarte> carte = joueur->getJeux()[indexCarte];
            if(!(carte->isRoi() || carte->isAtout() || carte->isBout())) {
                if(partie->getChien()->getCartes().size() != partie->getChien()->getTaille()) {
                    button->setStyleSheet(button->styleSheet()+QString::fromStdString("margin-bottom:50px;"));
                    partie->getChien()->ajouterCarte(carte);
                    if(partie->getChien()->getCartes().size() == partie->getChien()->getTaille()) {
                        partie->getFenetre()->setVisibleValider(true);
                    }
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
       partie->getPreneur()->removeCarte(carte, true);
       partie->getPaquet()->ajouterCarte(carte);
       points += carte->getValeur();
    }

    partie->getEquipeByJoueur(partie->getPreneur())->ajouterPoints(points);
    partie->getChien()->clearCartes(true);
    partie->setEtat(make_shared<JouerLeJeux>(partie));
    partie->demarrer();
}


