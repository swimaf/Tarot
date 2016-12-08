#ifndef CARREAU_H
#define CARREAU_H

#include "AForme.h"

using namespace std;

class Carreau  : public AForme
{
public:
    Carreau();
    virtual bool operator== (const ACarte* carte) const;

};

#endif // CARREAU_H
