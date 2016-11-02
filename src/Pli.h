#ifndef PLI_H
#define PLI_H

#include <QVector>
#include <memory>
#include "ACarte.h"
#include <unordered_map>

class Joueur;
class Pli
{
    public:
        Pli();
        void ajouterCarte(int indexJoueur, shared_ptr<ACarte> carte);
        int indexOfVainqueur();
        QVector<shared_ptr<ACarte>> getCartes();
        unordered_map<int, shared_ptr<ACarte>> getMap();
        double getPoints();
        shared_ptr<ACarte> getBase();
        int getJoueurBase();
        shared_ptr<ACarte> getCarte(int j);
        int getJoueurByCarte(shared_ptr<ACarte> carte);

    private:
        unordered_map<int, shared_ptr<ACarte>> cartes;
};

#endif // PLI_H
