#ifndef ATOUT_H
#define ATOUT_H

#include <string>
#include "ACarte.h"

using namespace std;


class Atout : public ACarte
{
    public:
        Atout(int);
        string afficher() const;
        double getValeur();
        string getURL() const;

        bool isBout();
        bool isAtout();
        bool operator== (const ACarte* carte) const ;
        string getName() const;
        int poids() const;
        string getType() const;


    protected :
        int val;


};

#endif // ATOUT_H
