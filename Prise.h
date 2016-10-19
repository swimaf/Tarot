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
        int seuil();

};

#endif // PRISE_H
