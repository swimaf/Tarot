#ifndef CARREAU_H
#define CARREAU_H

#include "AForme.h"

using namespace std;

class Carreau : public AForme
{
    public:
        Carreau(string p_name);
        Carreau(string p_name, Tete *valeur);
        string afficher() const;
        bool operator== (const ACarte* carte) const;


};

#endif // CARREAU_H
