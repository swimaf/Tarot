#include "Carreau.h"

using namespace std;

Carreau::Carreau(string p_name) : AForme(p_name)
{

}

Carreau::Carreau(string p_name, Tete* valeur) : AForme(p_name, valeur)
{

}

string Carreau::afficher() const{
    return ACarte::afficher()+" de ♦";
}

bool Carreau::operator== (const ACarte* carte) const {
    const Carreau *o = dynamic_cast<const Carreau*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}
