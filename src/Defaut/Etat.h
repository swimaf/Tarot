#ifndef ETAT_H
#define ETAT_H

#include "Partie.h"
#include <memory>

class Etat
{
    public:
        Etat(shared_ptr<Partie> partie);
        virtual void demarrer() = 0;
        virtual void demarrerHumain(int indexCarte) {}
        virtual void transition() {}
        virtual void continuer() {}
        virtual void choixEnchere(int indexCarte) {}




    protected:
        shared_ptr<Partie> partie;

};

#endif // ETAT_H
