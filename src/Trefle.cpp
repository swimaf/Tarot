#include "Trefle.h"

using namespace std;

Trefle::Trefle(Tete* valeur) : AForme(valeur)
{

}

string Trefle::afficher() const{
    return ACarte::afficher()+" de "+getType();
}

bool Trefle::operator== (const ACarte* carte) const {
    const Trefle *o = dynamic_cast<const Trefle*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}

string Trefle::getType() const {
    return "♣";
}
