#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <memory>
#include <vector>
#include "ACarte.h"
#include "Niveau.h"

using namespace std;

class Partie;
class Joueur
{
    public:
        Joueur(string n);
        string toString();
        vector<shared_ptr<ACarte>> getJeux();
        void ajouterCarte(shared_ptr<ACarte> carte);
        virtual bool choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Niveau> *niveau) = 0;
        string getNom();
        void clearCartes();
        virtual shared_ptr<ACarte> appelerRoi(vector<shared_ptr<ACarte>> rois) = 0;
        virtual vector<shared_ptr<ACarte>> selectionCartesChien(int taille) = 0;
        virtual shared_ptr<ACarte> selectionCarteAJouer() = 0;


    protected:
        string name;
        vector<shared_ptr<ACarte>> jeux;
};

#endif // JOUEUR_H
