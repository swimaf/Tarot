#include "Roi.h"

Roi::Roi(shared_ptr<AForme> f) : AValeur(4.5, 14, f)
{
    name = "Roi";
}

bool Roi::operator== (const ACarte* carte) const {
    const Roi *o = dynamic_cast<const Roi*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}

bool Roi::isRoi() const{
    return true;
}
