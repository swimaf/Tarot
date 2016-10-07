#include "Trefle.h"

using namespace std;

Trefle::Trefle(string p_name) : AForme(p_name)
{

}


Trefle::Trefle(string p_name, IValeur* valeur) : AForme(p_name, valeur)
{

}

string Trefle::afficher() {
    return ACarte::afficher()+" de ♣";
}
