#ifndef PRISE_H
#define PRISE_H

#include "Niveau.h"
#include <memory>

class Prise : public Niveau
{
    public:
        Prise();
        shared_ptr<Niveau> getSuivant();
        string getNom();
        int seuil();
        int multiplicateur();

};

#endif // PRISE_H
