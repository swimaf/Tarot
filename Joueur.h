#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <memory>
#include <vector>
#include "ACarte.h"

using namespace std;

class Joueur
{
    public:
        Joueur(string n);
        string toString();

    protected:
        string name;
        vector<shared_ptr<ACarte>> jeux;
};

#endif // JOUEUR_H
