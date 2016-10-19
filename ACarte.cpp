#include "ACarte.h"
#include "Coeur.h"
#include "Valet.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Roi.h"
#include "Excuse.h"

using namespace std;

ACarte::ACarte(std::string p_name)
{
    name = p_name;
}


string ACarte::afficher() const {
    return name;
}

string ACarte::getName() {
    return name;
}

bool ACarte::isRoi() {
    return false;
}

bool ACarte::equals(shared_ptr<ACarte> a) {
    return afficher().compare(a->afficher()) == 0;
}

int ACarte::compterNbBout(vector<shared_ptr<ACarte>> cartes){
    int res = 0;
    for(shared_ptr<ACarte> carte:cartes) {
        if(carte->isBout()) {
            ++res;
        }
    }
    return res;
}

int ACarte::compterNbAtout(vector<shared_ptr<ACarte>> cartes){
    int res = 0;
    for(shared_ptr<ACarte> carte:cartes) {
        if(carte->isAtout()) {
            ++res;
        }
    }
    return res;
}

int ACarte::compterPoint(vector<shared_ptr<ACarte>> cartes){
    double res = 0;
    for(shared_ptr<ACarte> carte:cartes) {
        res += carte->getValeur();
    }
    return res;
}

vector<shared_ptr<ACarte>> ACarte::getRois(vector<shared_ptr<ACarte>> cartes) {
    vector<shared_ptr<ACarte>> rois;
    for(shared_ptr<ACarte> carte:cartes) {
        if(carte->isRoi()) {
            rois.push_back(carte);
        }
    }
    return rois;
}

void ACarte::eraseElements(vector<shared_ptr<ACarte>> *cartes, vector<int> index) {
    for(int i:index) {
        cartes->erase(cartes->begin()+i);
    }
}


