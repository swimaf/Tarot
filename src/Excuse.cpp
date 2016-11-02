#include "Excuse.h"

Excuse::Excuse() : ACarte()
{
}


double Excuse::getValeur() {
    return 4.5;
}

string Excuse::getName() const {
    return "Excuse";
}

int Excuse::poids() const {
    return 0;
}

bool Excuse::isBout(){
    return true;
}

bool Excuse::isAtout(){
    return false;
}

bool Excuse::operator== (const ACarte* carte) const {
    const Excuse *o = dynamic_cast<const Excuse*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}


string Excuse::getType() const{
    return "Excuse";
}
