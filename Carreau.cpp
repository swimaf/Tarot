#include "Carreau.h"

using namespace std;

Carreau::Carreau(string p_name) : AForme(p_name)
{

}

Carreau::Carreau(string p_name, IValeur* valeur) : AForme(p_name, valeur)
{

}

string Carreau::afficher() {
    return ACarte::afficher()+" de ♦";
}
