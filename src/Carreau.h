#ifndef CARREAU_H
#define CARREAU_H

#include "AForme.h"

using namespace std;

class Carreau : public AForme
{
    public:
        Carreau(Tete *valeur);
        string afficher() const;
        bool operator== (const ACarte* carte) const;
        string getType() const;


};

#endif // CARREAU_H
