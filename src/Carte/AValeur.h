#ifndef AVALEUR_H
#define AVALEUR_H

#include "AForme.h"

using namespace std;

// Classe héritant de AForme (correspond au Decorator)
class AValeur : public AForme
{
    public:
        AValeur(double valeur, int poids, shared_ptr<AForme> f);
        // Redéfinition de fonctions
        virtual string getURL() const;
        virtual string getType() const;
        virtual bool operator== (const ACarte* carte) const = 0;

    protected:
        shared_ptr<AForme> forme;
};


#endif // AVALEUR_H
