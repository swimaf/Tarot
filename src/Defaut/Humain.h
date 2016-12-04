#ifndef HUMAIN_H
#define HUMAIN_H

#include "Joueur.h"

class Humain : public Joueur
{
    public:
        Humain(string n);
        QString getType();
        bool choixEnchere(shared_ptr<Partie> *partie);
        shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois);
        QVector<shared_ptr<ACarte>> selectionCartesChien(int taille);
        void selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie);
        void trierJeux();
        bool isHumain();
        void ajouterCarte(shared_ptr<ACarte> carte);


};

#endif
