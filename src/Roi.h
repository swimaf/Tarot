#ifndef ROI_H
#define ROI_H

#include "Tete.h"

class Roi : public Tete
{
    public:
        Roi();
        double getValeur();
        bool isRoi();
        int getPoids() const;
        string getName() const;
};

#endif // VALEURROI_H
