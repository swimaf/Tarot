#ifndef IA_H
#define IA_H

#include "StrategieJeu.h"

class Partie;
class IA : public StrategieJeu
{
    public:
        IA();
        bool choixEnchere(shared_ptr<Partie> *partie, QVector<shared_ptr<ACarte>> jeux) ;
        shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois, shared_ptr<Joueur> joueur) ;
        QVector<shared_ptr<ACarte>> selectionCartesChien(int taille, QVector<shared_ptr<ACarte>> jeux) ;
        void selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur) ;
        bool isHumain() ;
        QPushButton* ajouterCarte(shared_ptr<ACarte> carte) ;
        QString getType();
        void trierJeux(shared_ptr<Joueur> joueur);
};
#endif // IA_H
