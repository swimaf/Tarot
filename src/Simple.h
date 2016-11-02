#ifndef SIMPLE_H
#define SIMPLE_H

#include "Tete.h"

class Simple : public Tete
{
    public:
        Simple(int val);
        double getValeur();
        int getPoids() const;
        string getName() const;

    private:
        int val;
};

#endif // VALEURSIMPLE_H
