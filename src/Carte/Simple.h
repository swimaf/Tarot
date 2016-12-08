#ifndef SIMPLE_H
#define SIMPLE_H

#include "AValeur.h"

class Simple : public AValeur
{
    public:
        Simple(int poids, shared_ptr<AForme> f);
        virtual bool operator== (const ACarte* carte) const;
        virtual string getName() const;

};

#endif // SIMPLE_H
