#include "Trefle.h"

using namespace std;

Trefle::Trefle(string p_name) : AForme(p_name)
{

}


Trefle::Trefle(string p_name, Tete* valeur) : AForme(p_name, valeur)
{

}

string Trefle::afficher() const{
    return ACarte::afficher()+" de ♣";
}

bool Trefle::operator== (const ACarte* carte) const {
    const Trefle *o = dynamic_cast<const Trefle*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}
