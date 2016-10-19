#include "Paquet.h"
#include "Coeur.h"
#include "Pique.h"
#include "Carreau.h"
#include "Trefle.h"
#include "Valet.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Roi.h"
#include "Excuse.h"
#include "Atout.h"
#include "LePetit.h"
#include "Le21.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>


shared_ptr<Paquet> Paquet::instance=make_shared<Paquet>();


Paquet::Paquet()
{
    for(int i=1; i<11; i++) {
        cartes.push_back(make_shared<Coeur>(to_string(i)));
        cartes.push_back(make_shared<Pique>(to_string(i)));
        cartes.push_back(make_shared<Carreau>(to_string(i)));
        cartes.push_back(make_shared<Trefle>(to_string(i)));
    }

    cartes.push_back(make_shared<Coeur>("Valet", new Valet()));
    cartes.push_back(make_shared<Coeur>("Cavalier", new Cavalier()));
    cartes.push_back(make_shared<Coeur>("Dame", new Dame()));
    cartes.push_back(make_shared<Coeur>("Roi", new Roi()));

    cartes.push_back(make_shared<Pique>("Valet", new Valet()));
    cartes.push_back(make_shared<Pique>("Cavalier", new Cavalier()));
    cartes.push_back(make_shared<Pique>("Dame", new Dame()));
    cartes.push_back(make_shared<Pique>("Roi", new Roi()));

    cartes.push_back(make_shared<Carreau>("Valet", new Valet()));
    cartes.push_back(make_shared<Carreau>("Cavalier", new Cavalier()));
    cartes.push_back(make_shared<Carreau>("Dame", new Dame()));
    cartes.push_back(make_shared<Carreau>("Roi", new Roi()));

    cartes.push_back(make_shared<Trefle>("Valet", new Valet()));
    cartes.push_back(make_shared<Trefle>("Cavalier", new Cavalier()));
    cartes.push_back(make_shared<Trefle>("Dame", new Dame()));
    cartes.push_back(make_shared<Trefle>("Roi", new Roi()));


    cartes.push_back(make_shared<Excuse>());

    for(int i=2; i<21; i++) {
        cartes.push_back(make_shared<Atout>(to_string(i)));
    }

    cartes.push_back(make_shared<LePetit>());
    cartes.push_back(make_shared<Le21>());

}

vector<shared_ptr<ACarte>> Paquet::getCartes() {
    return cartes;
}

void Paquet::melanger() {
    srand (time(NULL));
    random_shuffle(cartes.begin(), cartes.end());
}


void Paquet::couper() {
    int randomVariable = rand() % getCartes().size();
    iter_swap(cartes.begin(),cartes.begin()+randomVariable);
}

shared_ptr<Paquet> Paquet::getInstance() {
    return instance;
}

void Paquet::clearCartes() {
    cartes = vector<shared_ptr<ACarte>>();
}

void Paquet::ajouterCartes(shared_ptr<ACarte> carte) {
    cartes.push_back(carte);
}

