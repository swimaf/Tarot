#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

using namespace std;

class Joueur
{
    public:
        Joueur(string n);
        string toString();

    protected:
        string name;
};

#endif // JOUEUR_H
