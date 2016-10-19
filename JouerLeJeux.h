#ifndef JOUERLEJEUX_H
#define JOUERLEJEUX_H

#include "Etat.h"

class JouerLeJeux: public Etat
{
    public:
        JouerLeJeux(shared_ptr<Partie> partie);
        void demarrer();
};

#endif // JOUERLEJEUX_H
