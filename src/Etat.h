#ifndef ETAT_H
#define ETAT_H

#include "Partie.h"
#include <memory>

class Etat
{
    public:
        Etat(shared_ptr<Partie> partie);
        virtual void demarrer() = 0;

    protected:
        shared_ptr<Partie> partie;

};

#endif // ETAT_H
