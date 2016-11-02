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
};

#endif // JOUERLEJEUX_H
