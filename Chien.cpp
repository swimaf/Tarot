#include "Chien.h"

Chien::Chien()
{

}

void Chien::ajouterCarte(shared_ptr<ACarte> carte) {
    cartes.push_back(carte);
}

int Chien::getTaille(){
    return taille;
}

vector<shared_ptr<ACarte>> Chien::getCartes() {
    return cartes;
}

void Chien::clearCartes() {
    cartes = vector<shared_ptr<ACarte>>();
}
