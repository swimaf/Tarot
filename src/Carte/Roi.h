#ifndef ROI_H
#define ROI_H

#include "AValeur.h"

class Roi : public AValeur
{
public:
    Roi(shared_ptr<AForme> f);
    virtual bool operator== (const ACarte* carte) const;
    virtual bool isRoi() const;

};

#endif // ROI_H
