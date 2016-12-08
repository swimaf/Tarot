#ifndef DAME_H
#define DAME_H

#include "AValeur.h"

class Dame : public AValeur
{
public:
    Dame(shared_ptr<AForme> f);
    virtual bool operator== (const ACarte* carte) const;
};


#endif // DAME_H
