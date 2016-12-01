#include "Coeur.h"

using namespace std;


Coeur::Coeur(Tete* valeur) : AForme(valeur)
{

}

string Coeur::afficher() const{
    return ACarte::afficher()+" de "+getType();
}

bool Coeur::operator== (const ACarte* carte) const {
    const Coeur *o = dynamic_cast<const Coeur*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}


string Coeur::getType() const {
    return "Coeur";
}

