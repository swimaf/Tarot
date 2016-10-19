#ifndef IA_H
#define IA_H

#include "Joueur.h"

class IA : public Joueur
{
    public:
        IA(string);
        string toString();
        bool choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Niveau> *niveau);
        shared_ptr<ACarte> appelerRoi(vector<shared_ptr<ACarte>> rois);
        vector<shared_ptr<ACarte>> selectionCartesChien(int taille);
        shared_ptr<ACarte> selectionCarteAJouer();
};

#endif // IA_H
