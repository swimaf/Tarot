#ifndef COEUR_H
#define COEUR_H

#include <string>
#include "AForme.h"

using namespace std;

class Coeur : public AForme
{
    public:
        Coeur(Tete *valeur);
        string afficher() const;
        bool operator== (const ACarte* carte) const;
        string getType() const;


};

#endif // COEUR_H
