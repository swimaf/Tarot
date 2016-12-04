#ifndef DISTRIBUER_H
#define DISTRIBUER_H

#include "Etat.h"
#include <memory>

class Distribuer : public Etat
{
    public:
        Distribuer(shared_ptr<Partie> partie);
        void demarrer();
        void continuer();

    private:
};

#endif // DISTRIBUER_H
