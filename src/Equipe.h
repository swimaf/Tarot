#ifndef EQUIPE_H
#define EQUIPE_H

#include "Joueur.h"
#include <QVector>
#include <memory>

class Equipe
{
    public:
        Equipe(QVector<shared_ptr<Joueur>> joueurs);
        Equipe(shared_ptr<Joueur> joueur);
        QVector<shared_ptr<Joueur>> getJoueurs();
        void ajouterPoints(double p);
        double getPoints();
        int getNbBouts();
        void setNbBouts(int nb);
        void ajouterBout(int nb);
        void joindreEquipe(shared_ptr<Equipe> equipe);
        bool operator== (Equipe* equipe);
        void afficher();


    private:
        QVector<shared_ptr<Joueur>> joueurs;
        double points;
        int nbBouts;

};

#endif // EQUIPE_H
