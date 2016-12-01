#include "Carreau.h"

using namespace std;


Carreau::Carreau(Tete* valeur) : AForme(valeur)
{

}

string Carreau::afficher() const{
    return ACarte::afficher()+" de "+getType();
}

bool Carreau::operator== (const ACarte* carte) const {
    const Carreau *o = dynamic_cast<const Carreau*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}

string Carreau::getType() const {
    return "Carreau";
}
