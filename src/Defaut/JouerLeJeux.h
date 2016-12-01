#ifndef JOUERLEJEUX_H
#define JOUERLEJEUX_H

#include "Etat.h"
#include "Pli.h"

class JouerLeJeux: public Etat
{
    public:
        JouerLeJeux(shared_ptr<Partie> partie);
        void demarrer();
        int nbDeBout(Pli pli, shared_ptr<ACarte> *excuse) ;
        void demarrerHumain(int);
        void transition();
        void nextJoueur();
        void resetPli();
        void continuer();



    private:
        int tour;
        int joueurCourant;
        Pli pli;

};

#endif // JOUERLEJEUX_H
