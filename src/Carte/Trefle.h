#ifndef TREFLE_H
#define TREFLE_H

#include "AForme.h"

using namespace std;

class Trefle : public AForme
{
public:
    Trefle();
    virtual bool operator== (const ACarte* carte) const;

};

#endif // TREFLE_H
