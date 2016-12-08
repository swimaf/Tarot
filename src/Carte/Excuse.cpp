#include "Excuse.h"

Excuse::Excuse() : ACarte(4.5,0,"Excuse","Excuse")
{
}

bool Excuse::isBout() const{
    return true;
}

bool Excuse::operator== (const ACarte* carte) const {
    const Excuse *o = dynamic_cast<const Excuse*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}

string Excuse::getURL() const {
    return name;
}

