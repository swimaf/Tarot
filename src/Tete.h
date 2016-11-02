#ifndef IVALEUR_H
#define IVALEUR_H

#include <string>

using namespace std;

class Tete
{
    public:
        Tete();
        virtual double getValeur() = 0;
        virtual bool isRoi();
        virtual int getPoids() const = 0;
        virtual string getName() const = 0;

};

#endif
