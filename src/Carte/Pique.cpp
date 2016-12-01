#include "Pique.h"


Pique::Pique(Tete* valeur) : AForme(valeur)
{

}
string Pique::afficher() const{
    return ACarte::afficher()+" de "+getType();
}



bool Pique::operator== (const ACarte* carte) const {
    const Pique *o = dynamic_cast<const Pique*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}


string Pique::getType() const {
    return "Pique";
}

