#include "Pique.h"

Pique::Pique(): AForme(0, "Pique", 0)
{
}

bool Pique::operator== (const ACarte* carte) const {
    const Pique *o = dynamic_cast<const Pique*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
