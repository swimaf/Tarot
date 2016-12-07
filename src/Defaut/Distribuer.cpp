#include "Distribuer.h"
#include "Constantes.h"
#include "Enchere.h"
#include <QVector>

Distribuer::Distribuer(shared_ptr<Partie> partie) : Etat(partie)
{

}

void Distribuer::demarrer() {

    int nbJoueur = partie->getJoueurs().size();
    partie->getPaquet()->couper();
    partie->clearEquipes();
    partie->getPreneur() = NULL;
    /**
     * Création du chien
     * */

    int i;

    for(i=0; i < partie->getChien()->getTaille(); i++) {
        partie->getChien()->ajouterCarte(partie->getPaquet()->getCartes().at(i));
    }

    /**
      * Distribution des cartes 3 par 3
      * */


    /**TODO Pour l'instant distibution par 3 cartes mais par la suite distribution random entre 1-3*/
    int indexDonneur = partie->getJoueurs().indexOf(partie->getDonneur());
    int joueurCourant = indexDonneur;
    int indexProchainDonneur = (indexDonneur+1) % partie->getJoueurs().size();
    partie->couperJoueur(indexProchainDonneur);

    int nbCartesPar3 = 0;

    for(i = partie->getChien()->getTaille(); i< Constantes::NB_CARTES; ++i) {

        if(nbCartesPar3 > 2) {
            joueurCourant = (joueurCourant == (nbJoueur-1)) ? 0 : joueurCourant+1;
            nbCartesPar3 = 0;
        }
        partie->getJoueurs()[joueurCourant]->ajouterCarte(partie->getPaquet()->getCartes().at(i));
        nbCartesPar3++;

    }


    partie->getPaquet()->clearCartes();
    partie->setDonneur(partie->getJoueurs()[indexProchainDonneur]);

    partie->setEtat(make_shared<Enchere>(partie));
    partie->demarrer();
}

void Distribuer::continuer() {
    demarrer();
}
