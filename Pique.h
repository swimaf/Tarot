#ifndef PIQUE_H
#define PIQUE_H

#include "AForme.h"
#include <string>

using namespace std;

class Pique : public AForme
{
    public:
        Pique(string p_name);
        Pique(string p_name, Tete *valeur);
        string afficher() const;
        bool operator== (const ACarte* carte) const;


};

#endif // PIQUE_H
