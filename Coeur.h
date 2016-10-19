#ifndef COEUR_H
#define COEUR_H

#include <string>
#include "AForme.h"

using namespace std;

class Coeur : public AForme
{
    public:
        Coeur(string p_name);
        Coeur(std::string p_name, Tete *valeur);
        string afficher() const;
        bool operator== (const ACarte* carte) const;


};

#endif // COEUR_H
