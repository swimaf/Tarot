#include "Valet.h"

Valet::Valet(shared_ptr<AForme> f) : AValeur(1.5, 11, f)
{
    name = "Valet";
}

bool Valet::operator== (const ACarte* carte) const {
    const Valet *o = dynamic_cast<const Valet*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
