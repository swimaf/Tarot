#ifndef VALET_H
#define VALET_H

#include "AValeur.h"

class Valet : public AValeur
{
public:
    Valet(shared_ptr<AForme> f);
    virtual bool operator== (const ACarte* carte) const;
};

#endif // VALET_H
