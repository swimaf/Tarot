#ifndef EXCUSE_H
#define EXCUSE_H

#include "ACarte.h"

using namespace std;

class Excuse : public ACarte
{
    public:
        Excuse();
        double getValeur();
        bool isBout();
        bool isAtout();
        bool operator== (const ACarte* carte) const;
        string getName() const;
        int poids() const;
        string getType() const;
        string getURL() const;

};

#endif // EXCLUSE_H
