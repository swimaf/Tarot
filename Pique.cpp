#include "Pique.h"

Pique::Pique(std::string p_name) : AForme(p_name)
{

}

Pique::Pique(string p_name, Tete* valeur) : AForme(p_name, valeur)
{

}
string Pique::afficher() const{
    return ACarte::afficher()+" de ♠";
}



bool Pique::operator== (const ACarte* carte) const {
    const Pique *o = dynamic_cast<const Pique*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}
