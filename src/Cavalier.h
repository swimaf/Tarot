#ifndef CAVALIER_H
#define CAVALIER_H


#include "Tete.h"

class Cavalier : public Tete
{
    public:
        Cavalier();
        double getValeur();

        int getPoids() const;
        string getName() const;

};

#endif
