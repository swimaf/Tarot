#include "Le21.h"

Le21::Le21() : Atout(21)
{
    valeur = 4.5;
}

bool Le21::isBout() const{
    return true;
}

bool Le21::operator== (const ACarte* carte) const {
    const Le21 *o = dynamic_cast<const Le21*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
