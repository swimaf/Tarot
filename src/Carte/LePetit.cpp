#include "LePetit.h"

LePetit::LePetit() : Atout(1)
{
    valeur = 4.5;
}

bool LePetit::isBout() const{
    return true;
}


bool LePetit::operator== (const ACarte* carte) const {
    const LePetit *o = dynamic_cast<const LePetit*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
