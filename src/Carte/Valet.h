#ifndef VALET_H
#define VALET_H

#include "Tete.h"


class Valet : public Tete
{
    public:
        Valet();
        double getValeur();
        int getPoids() const;
        string getName() const;
};

#endif // VALEURVALET_H
