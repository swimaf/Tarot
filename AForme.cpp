#include "AForme.h"
#include "ValeurSimple.h"

AForme::AForme(std::string p_name) : ACarte(p_name)
{
    iValeur = new ValeurSimple();
}

AForme::AForme(std::string p_name, IValeur *valeur) : ACarte(p_name)
{
    iValeur = valeur;
}

double AForme::getValeur() {
    return iValeur->getValeur();
}

std::string AForme::afficher() {
    return "Carte simple " + ACarte::afficher();
}
