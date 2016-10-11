#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.h"
#include <vector>
#include <memory>
#include "Chien.h"

class Etat;
class Partie
{
    public:
        Partie();
        vector<shared_ptr<Joueur>> getJoueurs();
        Chien getChien();
        void setChien(Chien &chien);

    private:
        vector<shared_ptr<Joueur>> joueurs;
        Chien *chien;
        Etat* etat;
};

#endif // PARTIE_H
