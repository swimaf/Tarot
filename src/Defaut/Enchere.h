#ifndef ENCHERE_H
#define ENCHERE_H

#include "Etat.h"

class Enchere : public Etat
{
    public:
        Enchere(shared_ptr<Partie> partie);
        void demarrer();
        void choixEnchere(int i);
        void recupererCarteSurTable();
        void creerEquipes();
        void transition();

};

#endif // ENCHERE_H
