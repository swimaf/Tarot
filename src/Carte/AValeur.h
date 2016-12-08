#ifndef AVALEUR_H
#define AVALEUR_H

#include "AForme.h"

using namespace std;

class AValeur : public AForme
{
    public:
        AValeur(double AValeur, int poids, shared_ptr<AForme> f);
        virtual string getURL() const;
        virtual string getType() const;
        virtual bool operator== (const ACarte* carte) const = 0;

    protected:
        shared_ptr<AForme> AForme;
};


#endif // AVALEUR_H
