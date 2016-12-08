#ifndef CAVALIER_H
#define CAVALIER_H

#include "AValeur.h"

class Cavalier : public AValeur
{
public:
    Cavalier(shared_ptr<AForme> f);
    virtual bool operator== (const ACarte* carte) const;
};

#endif // CAVALIER_H
