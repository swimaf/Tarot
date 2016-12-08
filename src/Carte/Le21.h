#ifndef LE21_H
#define LE21_H

#include "Atout.h"

using namespace std;


class Le21 : public Atout
{
    public:
        Le21();
        bool isBout() const;
        bool operator== (const ACarte* carte) const;

};


#endif // LE31_H
