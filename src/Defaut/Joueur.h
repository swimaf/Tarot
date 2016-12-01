#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <memory>
#include <QVector>
#include "../Carte/ACarte.h"
#include "Niveau.h"
#include "Pli.h"
#include <QBoxLayout>

using namespace std;

class Partie;
class Joueur
{
    public:
        Joueur(string n);
        string toString();
        QVector<shared_ptr<ACarte>> getJeux();
        virtual bool choixEnchere(shared_ptr<Partie> *partie) = 0;
        string getNom() const;
        void clearCartes();
        virtual shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois) = 0;
        virtual QVector<shared_ptr<ACarte>> selectionCartesChien(int taille) = 0;
        virtual void selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie) = 0;
        void removeCarte(shared_ptr<ACarte> carte);
        virtual void trierJeux();
        int getPoints();
        void ajouterPoints(int points);
        bool operator== (const Joueur* joueur) const;
        QVector<shared_ptr<ACarte>> getCartesJouable(Pli *pli);
        void setEmplacement(shared_ptr<QBoxLayout> emplacement);
        shared_ptr<QBoxLayout> getEmplacement();
        virtual bool isHumain() = 0;
        void setBoutons(shared_ptr<QHBoxLayout> e);
        shared_ptr<QHBoxLayout> getBoutons();
        void jouerCarte(shared_ptr<ACarte> carte);
        void resetEmplacement();
        virtual void ajouterCarte(shared_ptr<ACarte> carte) = 0;


    protected:
        string name;
        QVector<shared_ptr<ACarte>> jeux;
        shared_ptr<QBoxLayout> emplacement;
        shared_ptr<QHBoxLayout> action;
        int points;
};

#endif // JOUEUR_H
