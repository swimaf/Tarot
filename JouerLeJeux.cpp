#include "JouerLeJeux.h"
#include <QCoreApplication>
#include <iostream>
#include <QVector>


JouerLeJeux::JouerLeJeux(shared_ptr<Partie> partie) : Etat(partie)
{

}

void JouerLeJeux::demarrer() {
    cerr << "###################### JOUER LE JEUX ##############" << endl;
    int premierAJouer = 0;
    shared_ptr<ACarte> indexToRemove;
    int nbDeTour = partie->getJoueurs()[0]->getJeux().size();
    for(int i=0; i< nbDeTour;  i++) {
        cerr << "###################### JEUX " << i <<" ##############" << endl;

        for(shared_ptr<Joueur> joueur : partie->getJoueurs()) {
            shared_ptr<ACarte> carte = joueur->selectionCarteAJouer();
            /** A REDEFINIR **/
            if(carte != NULL) {
                cerr << carte->afficher() << endl;

                long int index = find(joueur->getJeux().begin(), joueur->getJeux().end(), carte) - joueur->getJeux().begin();
                joueur->getJeux().erase(joueur->getJeux().begin()+ index);
            }

        }
    }
}
