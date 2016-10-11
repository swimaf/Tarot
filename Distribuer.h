#ifndef DISTRIBUER_H
#define DISTRIBUER_H

#include "Etat.h"
#include <memory>

class Distribuer : public Etat
{
    public:
        Distribuer(Partie partie);
        void demarrer();

};

#endif // DISTRIBUER_H
