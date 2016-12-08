#ifndef ATOUT_H
#define ATOUT_H

#include <string>
#include "ACarte.h"

using namespace std;


class Atout : public ACarte
{
    public:
    Atout(int poids);
    virtual int getPoids() const;
    virtual bool isAtout() const;
    virtual bool operator== (const ACarte* carte) const;
    virtual string getURL() const;

};

#endif // ATOUT_H
