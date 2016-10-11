#ifndef EQUIPE_H
#define EQUIPE_H

#include "Joueur.h"
#include <vector>
#include <memory>

class Equipe
{
    public:
        Equipe(vector<shared_ptr<Joueur>> joueurs); // Au départ
        Equipe(vector<shared_ptr<Equipe>> equipes); // Quand découverte de la nouvelle equipe

    private:
        vector<shared_ptr<Joueur>> joueurs;
        double points;

};

#endif // EQUIPE_H
