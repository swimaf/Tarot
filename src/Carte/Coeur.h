#ifndef COEUR_H
#define COEUR_H

#include "AForme.h"

using namespace std;

class Coeur : public AForme
{
public:
    Coeur();
    virtual bool operator== (const ACarte* carte) const;

};

#endif // COEUR_H
