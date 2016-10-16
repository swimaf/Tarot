#include "Paquet.h"
#include "Coeur.h"
#include "Pique.h"
#include "Carreau.h"
#include "Trefle.h"
#include "ValeurValet.h"
#include "ValeurCavalier.h"
#include "ValeurDame.h"
#include "ValeurRoi.h"
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

    cartes.push_back(make_shared<Coeur>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Coeur>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Coeur>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Coeur>("Roi", new ValeurRoi()));

    cartes.push_back(make_shared<Pique>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Pique>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Pique>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Pique>("Roi", new ValeurRoi()));

    cartes.push_back(make_shared<Carreau>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Carreau>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Carreau>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Carreau>("Roi", new ValeurRoi()));

    cartes.push_back(make_shared<Trefle>("Valet", new ValeurValet()));
    cartes.push_back(make_shared<Trefle>("Cavalier", new ValeurCavalier()));
    cartes.push_back(make_shared<Trefle>("Dame", new ValeurDame()));
    cartes.push_back(make_shared<Trefle>("Roi", new ValeurRoi()));


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

