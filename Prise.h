#ifndef PRISE_H
#define PRISE_H

#include "Niveau.h"
#include <memory>

class Prise : public Niveau
{
    public:
        Prise();
        int getCoefficient();
        shared_ptr<Niveau> getSuivant();
        string getNom();
};

#endif // PRISE_H
