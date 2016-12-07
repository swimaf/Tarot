#ifndef STRATEGIEJEU_H
#define STRATEGIEJEU_H

#include <memory>
#include <QVector>
#include <QString>
#include "Pli.h"
#include "../Carte/ACarte.h"
#include <QPushButton>

class Joueur;
class Partie;
class StrategieJeu
{
public:
    StrategieJeu();
    virtual bool choixEnchere(shared_ptr<Partie> *partie, QVector<shared_ptr<ACarte>> jeux) = 0;
    virtual shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois, shared_ptr<Joueur> joueur) = 0;
    virtual QVector<shared_ptr<ACarte>> selectionCartesChien(int taille, QVector<shared_ptr<ACarte>> jeux) = 0;
    virtual void selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur) = 0;
    virtual bool isHumain() = 0;
    virtual QPushButton* ajouterCarte(shared_ptr<ACarte> carte) = 0;
    virtual QString getType() = 0;
    virtual void trierJeux(shared_ptr<Joueur> joueur) = 0;
};

#endif // STRATEGIEJEU_H
