#ifndef JOUEUR_H
#define JOUEUR_H


#include <string>
#include <memory>
#include <QVector>
#include <QLabel>
#include "../Carte/ACarte.h"
#include "Niveau.h"
#include "Pli.h"
#include <QBoxLayout>
#include <QWidget>

using namespace std;

class StrategieJeu;
class Partie;
class Joueur  : public enable_shared_from_this<Joueur>
{
    public:
        Joueur(string n);
        QString getType();
        QVector<shared_ptr<ACarte>> getJeux();
        bool choixEnchere(shared_ptr<Partie> *partie);
        string getNom();
        void clearCartes();
        shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois);
        QVector<shared_ptr<ACarte>> selectionCartesChien(int taille);
        void selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie);
        void removeCarte(shared_ptr<ACarte> carte, bool);
        virtual void trierJeux();
        int getPoints();
        void ajouterPoints(int points);
        bool operator== (Joueur* joueur);
        QVector<shared_ptr<ACarte>> getCartesJouable(Pli *pli);
        void setEmplacement(shared_ptr<QBoxLayout> emplacement);
        shared_ptr<QBoxLayout> getEmplacement();
        bool isHumain();
        void setBoutons(shared_ptr<QHBoxLayout> e);
        shared_ptr<QHBoxLayout> getBoutons();
        void jouerCarte(shared_ptr<ACarte> carte);
        void resetEmplacement();
        void ajouterCarte(shared_ptr<ACarte> carte);
        void removeSelectable();
        QVector<shared_ptr<ACarte>> getSelectable();
        QLabel* ajouterLabel();
        void setText(string text="");
        void changerStrategieIA();
        void changerStrategieHumain();
        void addWidgetToAction(QWidget *q);
        void addWidgetToEmplacement(QWidget *q);
        void setSelectable(QVector<shared_ptr<ACarte>> s);

    private:
        string name;
        QVector<shared_ptr<ACarte>> jeux;
        QVector<shared_ptr<ACarte>> selectable;
        shared_ptr<QBoxLayout> emplacement;
        shared_ptr<QHBoxLayout> action;
        QLabel* label;
        int points;
        shared_ptr<StrategieJeu> strategieCourante;
        shared_ptr<StrategieJeu> humain;
        shared_ptr<StrategieJeu> ia;
};

#endif // JOUEUR_H
