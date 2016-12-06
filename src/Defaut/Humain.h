#ifndef HUMAIN_H
#define HUMAIN_H

#include "StrategieJeu.h"
#include <memory>
#include "Partie.h"
#include "Joueur.h"
#include "Pli.h"
#include "../Carte/ACarte.h"

class Humain : public StrategieJeu
{
public:
    Humain();
    bool choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur) ;
    shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois, shared_ptr<Joueur> joueur) ;
    QVector<shared_ptr<ACarte>> selectionCartesChien(int taille, shared_ptr<Joueur> joueur) ;
    void selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur) ;
    bool isHumain() ;
    void ajouterCarte(shared_ptr<ACarte> carte, shared_ptr<Joueur> joueur) ;
    QString getType();
    void trierJeux(shared_ptr<Joueur> joueur);
};

#endif // HUMAIN_H
