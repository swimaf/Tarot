#ifndef HUMAIN_H
#define HUMAIN_H

#include "Joueur.h"

class Humain : public Joueur
{
    public:
        Humain(std::string n);
        std::string toString();
};

#endif // GUERRIER_H
