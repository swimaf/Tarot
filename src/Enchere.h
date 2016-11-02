#ifndef ENCHERE_H
#define ENCHERE_H

#include "Etat.h"

class Enchere : public Etat
{
    public:
        Enchere(shared_ptr<Partie> partie);
        void demarrer();
        void recupererCarteSurTable();
        void creerEquipes();
};

#endif // ENCHERE_H
