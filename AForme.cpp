#include "AForme.h"
#include "Simple.h"

AForme::AForme(std::string p_name) : ACarte(p_name)
{
    tete = new Simple();
}

AForme::AForme(string p_name, Tete *t) : ACarte(p_name)
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

bool AForme::isBout(){
    return false;
}

bool AForme::isAtout(){
    return false;
}
