#ifndef PIQUE_H
#define PIQUE_H

#include "AForme.h"
#include <string>

using namespace std;

class Pique : public AForme
{
    public:
        Pique();
        Pique(Tete *valeur);
        string afficher() const;
        bool operator== (const ACarte* carte) const;
        string getType() const;



};

#endif // PIQUE_H
