#include "Chien.h"

Chien::Chien(int taille) : taille(taille)
{

}

void Chien::ajouterCarte(auto &carte) {
    cartes.push_back(carte);
}

int Chien::getTaille(){
    return taille;
}

vector<shared_ptr<ACarte>> Chien::getCartes() {
    return cartes;
}
