#include "Cavalier.h"

Cavalier::Cavalier(shared_ptr<AForme> f) : AValeur(2.5, 12, f)
{
    name = "Cavalier";
}

bool Cavalier::operator== (const ACarte* carte) const {
    const Cavalier *o = dynamic_cast<const Cavalier*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
