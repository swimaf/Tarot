#ifndef ATOUT_H
#define ATOUT_H

#include <string>
#include "ACarte.h"

using namespace std;


class Atout : public ACarte
{
    public:
        Atout(string);
        string afficher();
        double getValeur();

};

#endif // ATOUT_H
