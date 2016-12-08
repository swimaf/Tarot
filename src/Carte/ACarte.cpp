#include "ACarte.h"

using namespace std;

ACarte::ACarte(double valeur, int poids, string type, string name) : valeur(valeur), type(type), poids (poids), name(name)
{

}

string ACarte::getName() const {
    return name;
}

double ACarte::getValeur() const{
    return valeur;
}

string ACarte::getType() const{
    return type;
}

int ACarte::getPoids() const {
    return poids;
}

bool ACarte::isRoi() const{
    return false;
}

bool ACarte::isBout() const{
    return false;
}

bool ACarte::isAtout() const{
    return false;
}

bool ACarte::equals(shared_ptr<ACarte> a) {
    return getURL().compare(a->getURL()) == 0;
}

int ACarte::compterNbBout(QVector<shared_ptr<ACarte>> cartes){
    int res = 0;
    for(shared_ptr<ACarte> carte:cartes) {
        if(carte->isBout()) {
            ++res;
        }
    }
    return res;
}

int ACarte::compterNbAtout(QVector<shared_ptr<ACarte>> cartes){
    int res = 0;
    for(shared_ptr<ACarte> carte:cartes) {
        if(carte->isAtout()) {
            ++res;
        }
    }
    return res;
}

int ACarte::compterPoint(QVector<shared_ptr<ACarte>> cartes){
    double res = 0;
    for(shared_ptr<ACarte> carte:cartes) {
        res += carte->getValeur();
    }
    return res;
}

QVector<shared_ptr<ACarte>> ACarte::getRois(QVector<shared_ptr<ACarte>> cartes) {
    QVector<shared_ptr<ACarte>> rois;
    for(shared_ptr<ACarte> carte:cartes) {
        if(carte->isRoi()) {
            rois.push_back(carte);
        }
    }
    return rois;
}

void ACarte::eraseElements(QVector<shared_ptr<ACarte>> *cartes, QVector<int> index) {
    for(int i:index) {
        cartes->erase(cartes->begin()+i);
    }
}

QVector<shared_ptr<ACarte>> ACarte::filtre(string type, QVector<shared_ptr<ACarte>> base) {
    QVector<shared_ptr<ACarte>> cartes;
    for(shared_ptr<ACarte> carte : base) {
        if(carte->getType().compare(type) == 0) {
            cartes.push_back(carte);
        }
    }
    return cartes;
}

QVector<shared_ptr<ACarte>> ACarte::filtreByValue(double val, QVector<shared_ptr<ACarte>> base) {
    QVector<shared_ptr<ACarte>> cartes;
    for(shared_ptr<ACarte> carte : base) {
        if(carte->getPoids() > val) {
            cartes.push_back(carte);
        }
    }
    return cartes;
}


