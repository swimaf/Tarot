#include "Paquet.h"
#include "../Carte/Coeur.h"
#include "../Carte/Pique.h"
#include "../Carte/Carreau.h"
#include "../Carte/Trefle.h"
#include "../Carte/Valet.h"
#include "../Carte/Simple.h"
#include "../Carte/Cavalier.h"
#include "../Carte/Dame.h"
#include "../Carte/Roi.h"
#include "../Carte/Excuse.h"
#include "../Carte/Atout.h"
#include "../Carte/LePetit.h"
#include "../Carte/Le21.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>


shared_ptr<Paquet> Paquet::instance=make_shared<Paquet>();


Paquet::Paquet()
{
    for(int i=1; i<11; i++) {
        cartes.push_back(make_shared<Simple>(i, make_shared<Coeur>()));
        cartes.push_back(make_shared<Simple>(i, make_shared<Carreau>()));
        cartes.push_back(make_shared<Simple>(i, make_shared<Pique>()));
        cartes.push_back(make_shared<Simple>(i, make_shared<Trefle>()));

    }

    cartes.push_back(make_shared<Valet>(make_shared<Coeur>()));
    cartes.push_back(make_shared<Cavalier>(make_shared<Coeur>()));
    cartes.push_back(make_shared<Dame>(make_shared<Coeur>()));
    cartes.push_back(make_shared<Roi>(make_shared<Coeur>()));


    cartes.push_back(make_shared<Valet>(make_shared<Carreau>()));
    cartes.push_back(make_shared<Cavalier>(make_shared<Carreau>()));
    cartes.push_back(make_shared<Dame>(make_shared<Carreau>()));
    cartes.push_back(make_shared<Roi>(make_shared<Carreau>()));

    cartes.push_back(make_shared<Valet>(make_shared<Pique>()));
    cartes.push_back(make_shared<Cavalier>(make_shared<Pique>()));
    cartes.push_back(make_shared<Dame>(make_shared<Pique>()));
    cartes.push_back(make_shared<Roi>(make_shared<Pique>()));

    cartes.push_back(make_shared<Valet>(make_shared<Trefle>()));
    cartes.push_back(make_shared<Cavalier>(make_shared<Trefle>()));
    cartes.push_back(make_shared<Dame>(make_shared<Trefle>()));
    cartes.push_back(make_shared<Roi>(make_shared<Trefle>()));


    cartes.push_back(make_shared<Excuse>());

    for(int i=2; i<21; i++) {
        cartes.push_back(make_shared<Atout>(i));
    }

    cartes.push_back(make_shared<LePetit>());
    cartes.push_back(make_shared<Le21>());

}

QVector<shared_ptr<ACarte>> Paquet::getCartes() {
    return cartes;
}

void Paquet::melanger() {
    srand (time(NULL));
    random_shuffle(cartes.begin(), cartes.end());
}


void Paquet::couper() {
    int randomVariable = rand() % getCartes().size();
    rotate(cartes.begin(),cartes.begin()+randomVariable,cartes.end());
}

shared_ptr<Paquet> Paquet::getInstance() {
    return instance;
}

void Paquet::clearCartes() {
    cartes = QVector<shared_ptr<ACarte>>();
}

void Paquet::ajouterCartes(QVector<shared_ptr<ACarte>> carts) {
    for(shared_ptr<ACarte> carte : carts) {
        cartes.push_back(carte);
    }
}


void Paquet::ajouterCarte(shared_ptr<ACarte> carte) {
    cartes.push_back(carte);
}


