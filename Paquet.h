#ifndef PAQUET_H
#define PAQUET_H

#include "ACarte.h"
#include <memory>

class Paquet
{
    public:
        static Paquet& getInstance();
        vector<shared_ptr<ACarte>> getCartes();
        void melanger();
        void couper();


    private:
        vector<shared_ptr<ACarte>> cartes;
        Paquet();
        static Paquet instance;

};

#endif // PAQUET_H
