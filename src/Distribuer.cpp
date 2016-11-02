#include "Distribuer.h"
#include <QCoreApplication>
#include <iostream>
#include "Constantes.h"
#include "Enchere.h"
#include <QVector>

Distribuer::Distribuer(shared_ptr<Partie> partie) : Etat(partie)
{

}

void Distribuer::demarrer() {
    cerr << "############# DISTRIBUTION DU JEUX ###########" <<endl;

    /**
      * INITIALISATION D'UNE MANCHE
      *
      * */

    cerr << "Carte paquet : " << partie->getPaquet()->getCartes().size() << endl;
    int nbJoueur = partie->getJoueurs().size();
    partie->getPaquet()->couper();
    partie->clearEquipes();
    partie->getPreneur() = NULL;

    /**
     * Création du chien
     * */

    int nbCarteDansChien = 3 + (Constantes::NB_CARTES-3) % nbJoueur;
    int i;

    for(i=0; i < nbCarteDansChien; i++) {
        partie->getChien()->ajouterCarte(partie->getPaquet()->getCartes().at(i));
    }

    /**
      * Distribution des cartes 3 par 3
      * */

    cerr << "Donneur " << partie->getDonneur()->getNom() << endl;

    /**TODO Pour l'instant distibution par 3 cartes mais par la suite distribution random entre 1-3*/
    int indexDonneur = partie->getJoueurs().indexOf(partie->getDonneur());
    int joueurCourant = indexDonneur;
    int indexProchainDonneur = (indexDonneur+1) % partie->getJoueurs().size();
    partie->couperJoueur(indexProchainDonneur);

    int nbCartesPar3 = 0; //

    for(i = nbCarteDansChien; i< Constantes::NB_CARTES; ++i) {
        if(nbCartesPar3 > 2) {
            joueurCourant = (joueurCourant == (nbJoueur-1)) ? 0 : ++joueurCourant;
            nbCartesPar3 = 0;
        }
        partie->getJoueurs()[joueurCourant]->ajouterCarte(partie->getPaquet()->getCartes().at(i));
        nbCartesPar3++;
    }


    partie->getPaquet()->clearCartes();
    partie->setDonneur(partie->getJoueurs()[indexProchainDonneur]);

    partie->setEtat(make_shared<Enchere>(partie));
    for(shared_ptr<Joueur> j:partie->getJoueurs()) {
        cerr << j->getNom() << endl;
    }

    cerr << "NB joueurs dans partie : "<< partie->getJoueurs().size() <<endl;
    cerr << "NB carte dans paquet : " << partie->getPaquet()->getCartes().size() <<endl;

    for(shared_ptr<Joueur> joueur : partie->getJoueurs()) {
        cerr << "NB carte dans jeux de Joueur : "<< joueur->getJeux().size() <<endl;
    }


}


/*void Distribuer::afficher() {
 *
 * for(auto &carte : partie.getPaquet()->getCartes()) {
        cerr << carte->afficher() << " , valeur : " << carte->getValeur() <<endl;
    }
    cerr << partie.getPaquet()->getCartes().size() <<endl;
}*/
