#ifndef EXCUSE_H
#define EXCUSE_H

#include "ACarte.h"

using namespace std;

class Excuse : public ACarte
{
    public:
        Excuse();
        virtual bool isBout() const;
        virtual bool operator== (const ACarte* carte) const;
        virtual string getURL() const;

};

#endif // EXCLUSE_H
