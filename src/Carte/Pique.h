#ifndef PIQUE_H
#define PIQUE_H

#include "AForme.h"

using namespace std;

class Pique : public AForme
{
public:
    Pique();
    virtual bool operator== (const ACarte* carte) const;

};

#endif // PIQUE_H
