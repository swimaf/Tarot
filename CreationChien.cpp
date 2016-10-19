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

    for(shared_ptr<ACarte> carte:partie->getChien()->getCartes()) {
        partie->getPreneur()->ajouterCarte(carte);
    }
    partie->getChien()->clearCartes();

    vector<shared_ptr<ACarte>> cartes = partie->getPreneur()->selectionCartesChien(tailleChien);

    for(shared_ptr<ACarte> carte:cartes) {
        partie->getChien()->ajouterCarte(carte);
    }

    for(shared_ptr<ACarte> carte:cartes) {
        cerr << carte->afficher() << endl;
    }

    partie->setEtat(make_shared<JouerLeJeux>(partie));

}
