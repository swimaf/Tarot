#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <memory>
#include <QVector>
#include "ACarte.h"
#include "Niveau.h"
#include "Pli.h"

using namespace std;

class Partie;
class Joueur
{
    public:
        Joueur(string n);
        string toString();
        QVector<shared_ptr<ACarte>> getJeux();
        void ajouterCarte(shared_ptr<ACarte> carte);
        virtual bool choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Niveau> *niveau) = 0;
        string getNom() const;
        void clearCartes();
        virtual shared_ptr<ACarte> appelerRoi(QVector<shared_ptr<ACarte>> rois) = 0;
        virtual QVector<shared_ptr<ACarte>> selectionCartesChien(int taille) = 0;
        virtual shared_ptr<ACarte> selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie) = 0;
        void removeCarte(shared_ptr<ACarte> carte);
        virtual void trierJeux();
        int getPoints();
        void ajouterPoints(int points);
        bool operator== (const Joueur* joueur) const;
        QVector<shared_ptr<ACarte>> getCartesJouable(Pli *pli);

    protected:
        string name;
        QVector<shared_ptr<ACarte>> jeux;
        int points;
};

#endif // JOUEUR_H
