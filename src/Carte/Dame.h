#ifndef DAME_H
#define DAME_H


#include "Tete.h"

class Dame : public Tete
{
    public:
        Dame();
        double getValeur();
        int getPoids() const;
        string getName() const;
};

#endif // VALEURDAME_H
