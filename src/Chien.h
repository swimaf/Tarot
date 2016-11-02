#ifndef CHIEN_H
#define CHIEN_H

#include <QVector>
#include <memory>
#include "ACarte.h"

using namespace std;

class Chien
{
    public:
        Chien();
        int getTaille();
        QVector<shared_ptr<ACarte>> getCartes();
        void ajouterCarte(shared_ptr<ACarte> carte);
        void clearCartes();


    private:
        int taille;
        QVector<shared_ptr<ACarte>> cartes;
};

#endif // CHIEN_H
