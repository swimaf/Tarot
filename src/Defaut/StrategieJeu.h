#ifndef STRATEGIEJEU_H
#define STRATEGIEJEU_H

#include <memory>
#include <QVector>
#include <QString>
#include "Pli.h"
#include "Joueur.h"
#include "../Carte/ACarte.h"

class Partie;

class StrategieJeu
{
public:
    StrategieJeu();
    virtual bool choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur) = 0;
    virtual shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois, shared_ptr<Joueur> joueur) = 0;
    virtual QVector<shared_ptr<ACarte>> selectionCartesChien(int taille, shared_ptr<Joueur> joueur) = 0;
    virtual void selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur) = 0;
    virtual bool isHumain() = 0;
    virtual void ajouterCarte(shared_ptr<ACarte> carte, shared_ptr<Joueur> joueur) = 0;
    virtual QString getType() = 0;
    virtual void trierJeux(shared_ptr<Joueur> joueur) = 0;
};

#endif // STRATEGIEJEU_H
