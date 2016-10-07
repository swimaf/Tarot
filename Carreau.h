#ifndef CARREAU_H
#define CARREAU_H

#include "AForme.h"

using namespace std;

class Carreau : public AForme
{
    public:
        Carreau(string p_name);
        Carreau(string p_name, IValeur *valeur);
        string afficher();

};

#endif // CARREAU_H
