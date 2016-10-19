#include "Excuse.h"

Excuse::Excuse() : ACarte("Excuse")
{
}


double Excuse::getValeur() {
    return 4.5;
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
