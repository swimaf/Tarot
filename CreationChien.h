#ifndef CREATIONCHIEN_H
#define CREATIONCHIEN_H

#include "Etat.h"

class CreationChien : public Etat
{
    public:
        CreationChien(shared_ptr<Partie> partie);
        void demarrer();
};

#endif // CREATIONCHIEN_H
