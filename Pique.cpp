#include "Pique.h"

Pique::Pique(std::string p_name) : AForme(p_name)
{

}

Pique::Pique(string p_name, IValeur* valeur) : AForme(p_name, valeur)
{

}
string Pique::afficher() {
    return ACarte::afficher()+" de ♠";
}
