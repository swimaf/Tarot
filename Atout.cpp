#include "Atout.h"


Atout::Atout(string name) : ACarte(name)
{}

string Atout::afficher() {
    return ACarte::afficher()+ " d'Atout";
}

double Atout::getValeur() {
    return 0.5;
}


