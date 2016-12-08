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
        cartes.push_back(make_shared<Simple>(i, make_shared<Coeur>());
        cartes.push_back(make_shared<Pique>(new Simple(i)));
        cartes.push_back(make_shared<Trefle>(new Simple(i)));
        cartes.push_back(make_shared<Carreau>(new Simple(i)));
    }

    cartes.push_back(make_shared<Coeur>(new Valet()));
    cartes.push_back(make_shared<Coeur>(new Cavalier()));
    cartes.push_back(make_shared<Coeur>(new Dame()));
    cartes.push_back(make_shared<Coeur>(new Roi()));

    cartes.push_back(make_shared<Pique>(new Valet()));
    cartes.push_back(make_shared<Pique>(new Cavalier()));
    cartes.push_back(make_shared<Pique>(new Dame()));
    cartes.push_back(make_shared<Pique>(new Roi()));

    cartes.push_back(make_shared<Carreau>(new Valet()));
    cartes.push_back(make_shared<Carreau>(new Cavalier()));
    cartes.push_back(make_shared<Carreau>(new Dame()));
    cartes.push_back(make_shared<Carreau>(new Roi()));

    cartes.push_back(make_shared<Trefle>(new Valet()));
    cartes.push_back(make_shared<Trefle>(new Cavalier()));
    cartes.push_back(make_shared<Trefle>(new Dame()));
    cartes.push_back(make_shared<Trefle>(new Roi()));


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


