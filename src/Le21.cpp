#include "Le21.h"

Le21::Le21() : Atout(21)
{
}


double Le21::getValeur() {
    return 4.5;
}


bool Le21::isBout(){
    return true;
}

bool Le21::operator== (const ACarte* carte) const {
    const Le21 *o = dynamic_cast<const Le21*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}
