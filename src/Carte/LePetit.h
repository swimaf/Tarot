#ifndef LEPETIT_H
#define LEPETIT_H

#include "Atout.h"

using namespace std;


class LePetit: public Atout
{
    public:
        LePetit();
        double getValeur();
        bool isBout();
        bool operator== (const ACarte* carte) const;

};

#endif // LEPETIT_H
