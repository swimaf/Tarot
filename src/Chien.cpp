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

QVector<shared_ptr<ACarte>> Chien::getCartes() {
    return cartes;
}

void Chien::clearCartes() {
    cartes = QVector<shared_ptr<ACarte>>();
}
