#ifndef PAQUET_H
#define PAQUET_H

#include "ACarte.h"
#include <memory>

class Paquet
{
    public:
        static shared_ptr<Paquet> getInstance();
        QVector<shared_ptr<ACarte>> getCartes();
        void ajouterCartes(QVector<shared_ptr<ACarte>> carte);
        void ajouterCarte(shared_ptr<ACarte> carte);
        void melanger();
        Paquet();
        void couper();
        void clearCartes();

    private:
        QVector<shared_ptr<ACarte>> cartes;
        static shared_ptr<Paquet> instance;

};

#endif // PAQUET_H
