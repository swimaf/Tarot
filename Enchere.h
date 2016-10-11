#ifndef ENCHERE_H
#define ENCHERE_H

#include "Etat.h"
#include "Niveau.h"

class Enchere : public Etat
{
    public:
        Enchere(Partie partie);
        void demarrer();

    private:
        Niveau *niveau;
};

#endif // ENCHERE_H
