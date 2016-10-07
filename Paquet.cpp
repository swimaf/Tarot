#include "Paquet.h"
#include "Coeur.h"
#include "Pique.h"
#include "Carreau.h"
#include "Trefle.h"
#include "ValeurValet.h"
#include "ValeurCavalier.h"
#include "ValeurDame.h"
#include "ValeurRoi.h"
#include "Excluse.h"
#include "Atout.h"
#include "LePetit.h"
#include "Le21.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>


Paquet Paquet::instance=Paquet();


Paquet::Paquet()
{
    for(int i=1; i<11; i++) {
        cartes.push_back(make_shared<Coeur>(to_string(i)));
    }
    cartes.push_back(make_shared<Coeur>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Coeur>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Coeur>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Coeur>("Roi", new ValeurRoi()));


    for(int i=1; i<11; i++) {
        cartes.push_back(make_shared<Pique>(to_string(i)));
    }
    cartes.push_back(make_shared<Pique>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Pique>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Pique>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Pique>("Roi", new ValeurRoi()));

    for(int i=1; i<11; i++) {
        cartes.push_back(make_shared<Carreau>(to_string(i)));
    }
    cartes.push_back(make_shared<Carreau>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Carreau>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Carreau>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Carreau>("Roi", new ValeurRoi()));

    for(int i=1; i<11; i++) {
        cartes.push_back(make_shared<Trefle>(to_string(i)));
    }
    cartes.push_back(make_shared<Trefle>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Trefle>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Trefle>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Trefle>("Roi", new ValeurRoi()));


    cartes.push_back(make_shared<Excluse>());

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
    random_shuffle(cartes.begin(), cartes.end());

}

Paquet& Paquet::getInstance() {
    return instance;
}

