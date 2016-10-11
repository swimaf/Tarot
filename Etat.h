#ifndef ETAT_H
#define ETAT_H

#include "Partie.h"
#include <memory>

class Etat
{
    public:
        Etat(Partie partie);
        virtual void demarrer() = 0;

    protected:
        Partie partie;

};

#endif // ETAT_H
