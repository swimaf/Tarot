#ifndef TREFLE_H
#define TREFLE_H

#include "AForme.h"
#include <string>

using namespace std;

class Trefle : public AForme
{
    public:
        Trefle(string name);
        Trefle(string p_name, IValeur *valeur);
        string afficher();

};

#endif // TREFLE_H
