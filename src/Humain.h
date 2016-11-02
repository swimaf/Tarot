#ifndef HUMAIN_H
#define HUMAIN_H

#include "Joueur.h"

class Humain : public Joueur
{
    public:
        Humain(string n);
        string toString();
        bool choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Niveau> *niveau);
        shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois);
        QVector<shared_ptr<ACarte>> selectionCartesChien(int taille);
        shared_ptr<ACarte> selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie);
        void trierJeux();

};

#endif
