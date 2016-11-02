#include "AForme.h"
#include "Simple.h"

AForme::AForme(Tete *t) : ACarte()
{
    tete = t;
}

double AForme::getValeur() {
    return tete->getValeur();
}

bool AForme::isRoi() {
    return tete->isRoi();
}

string AForme::afficher() const {
    return "Carte simple " + ACarte::afficher();
}

string AForme::getName() const {
    return tete->getName();
}

int AForme::poids() const {
    return tete->getPoids();
}


bool AForme::isBout(){
    return false;
}

bool AForme::isAtout(){
    return false;
}
