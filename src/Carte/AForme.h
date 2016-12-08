#ifndef AFORME_H
#define AFORME_H

#include "ACarte.h"
#include <string>

using namespace std;

// Classe héritant de ACarte
class AForme : public ACarte
{
    public:
        AForme(double valeur, string type, int poids);
        // Fonctions redéfinies
        virtual string getURL() const;
        virtual bool operator== (const ACarte* carte) const = 0;
};


#endif // AFORME_H
