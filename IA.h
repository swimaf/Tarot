#ifndef IA_H
#define IA_H

#include "Joueur.h"

class IA : public Joueur
{
    public:
        IA(string);
        string toString();
        bool choixEnchere(shared_ptr<Partie> partie, shared_ptr<Niveau> *niveau);
        shared_ptr<ACarte> appelerRoi();

};

#endif // IA_H
