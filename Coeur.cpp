#include "Coeur.h"

using namespace std;

Coeur::Coeur(string p_name) : AForme(p_name)
{

}

Coeur::Coeur(string p_name, IValeur* valeur) : AForme(p_name, valeur)
{

}

string Coeur::afficher() {
    return ACarte::afficher()+" de ♥";
}
