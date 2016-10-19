#ifndef ATOUT_H
#define ATOUT_H

#include <string>
#include "ACarte.h"

using namespace std;


class Atout : public ACarte
{
    public:
        Atout(string);
        string afficher() const;
        double getValeur();
        bool isBout();
        bool isAtout();
        bool operator== (const ACarte* carte) const ;


};

#endif // ATOUT_H
