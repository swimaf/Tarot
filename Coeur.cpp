#include "Coeur.h"

using namespace std;

Coeur::Coeur(string p_name) : AForme(p_name)
{

}

Coeur::Coeur(string p_name, Tete* valeur) : AForme(p_name, valeur)
{

}

string Coeur::afficher() const{
    return ACarte::afficher()+" de ♥";
}

bool Coeur::operator== (const ACarte* carte) const {
    const Coeur *o = dynamic_cast<const Coeur*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}
