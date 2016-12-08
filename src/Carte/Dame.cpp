#include "Dame.h"

Dame::Dame(shared_ptr<AForme> f) : AValeur(3.5, 13, f)
{
    name = "Dame";
}

bool Dame::operator== (const ACarte* carte) const {
    const Dame *o = dynamic_cast<const Dame*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
