#ifndef TREFLE_H
#define TREFLE_H

#include "AForme.h"
#include <string>

using namespace std;

class Trefle : public AForme
{
    public:
        Trefle(string name);
        Trefle(string p_name, Tete *valeur);
        string afficher() const;
        bool operator== (const ACarte* carte) const;


};

#endif // TREFLE_H
