#ifndef CHIEN_H
#define CHIEN_H

#include <QVector>
#include <memory>
#include <QHBoxLayout>
#include "../Carte/ACarte.h"

using namespace std;

class Chien
{
    public:
        Chien(int n);
        int getTaille();
        QVector<shared_ptr<ACarte>> getCartes();
        void ajouterCarte(shared_ptr<ACarte> carte);
        void clearCartes(bool);
        void setCartes(QVector<shared_ptr<ACarte>> c);
        void setLayout(shared_ptr<QHBoxLayout>);
        void montrerChien();
        void removeCarte(shared_ptr<ACarte> carte);

    private:
        int taille;
        QVector<shared_ptr<ACarte>> cartes;
        shared_ptr<QHBoxLayout> layout;

};

#endif // CHIEN_H
