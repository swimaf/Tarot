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

    cerr << "\nLE CHIEN :\n";
    for(shared_ptr<ACarte> carte:partie->getChien()->getCartes()) {
        cerr << carte->afficher() << endl;
        partie->getPreneur()->ajouterCarte(carte);
    }
    partie->getChien()->clearCartes();

    /** TRIE DES JEUX DES JOUEURS **/
    for(shared_ptr<Joueur> joueur:partie->getJoueurs()){
        joueur->trierJeux();
    }


    QVector<shared_ptr<ACarte>> cartes = partie->getPreneur()->selectionCartesChien(tailleChien);

    double points = 0;
    for(shared_ptr<ACarte> carte:cartes) {
       partie->getPreneur()->removeCarte(carte);
       partie->getPaquet()->ajouterCarte(carte);
       points += carte->getValeur();
    }

    partie->getEquipeByJoueur(partie->getPreneur())->ajouterPoints(points);

    cerr << "REMPLACER PAR :" << endl;
    for(shared_ptr<ACarte> carte:cartes) {
        cerr << carte->afficher() << endl;
    }


    partie->setEtat(make_shared<JouerLeJeux>(partie));

}
