#include "ACarte.h"
#include "Coeur.h"
#include "Valet.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Roi.h"
#include "Excuse.h"

using namespace std;

ACarte::ACarte()
{
}


string ACarte::afficher() const {
    return getName();
}


bool ACarte::isRoi() {
    return false;
}

bool ACarte::equals(shared_ptr<ACarte> a) {
    return afficher().compare(a->afficher()) == 0;
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
        if(carte->poids() > val) {
            cartes.push_back(carte);
        }
    }
    return cartes;
}


