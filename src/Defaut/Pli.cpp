#include "Pli.h"

Pli::Pli()
{

}

void Pli::ajouterCarte(int indexJoueur, shared_ptr<ACarte> carte){
    cartes[indexJoueur] = carte;
}

int Pli::indexOfVainqueur(){
    int meneur = cartes.begin()->first;
    string typeBase = cartes.begin()->second->getType();
    for (auto const& element : cartes) {
        if(element.second->isAtout() || typeBase.compare(element.second->getType()) == 0 ) {
            if(cartes[meneur]->getPoids() < element.second->getPoids()) {
                meneur = element.first;
            }
        }
    }
    return meneur;
}

shared_ptr<ACarte> Pli::getBase() {
    return cartes.at(0);
}


QVector<shared_ptr<ACarte>> Pli::getCartes() {
    QVector<shared_ptr<ACarte>> values;
    for (auto const& element : cartes) {
      values.push_back(element.second);
    }
    return values;
}

double Pli::getPoints() {
    double res =0;
    for (auto const& element : cartes) {
        res+= element.second->getValeur();
    }
    return res;
}

unordered_map<int, shared_ptr<ACarte>> Pli::getMap(){
    return cartes;
}

shared_ptr<ACarte> Pli::getCarte(int j) {
    return cartes[j];
}

int Pli::getJoueurBase() {
    for (auto const& element : cartes) {
        return element.first;
    }
    return NULL;
}


int Pli::getJoueurByCarte(shared_ptr<ACarte> carte) {
    for (auto const& element : cartes) {
        if(carte == element.second) {
            return element.first;
        }
    }
    return NULL;
}


void Pli::clear() {
    cartes.clear();
}
