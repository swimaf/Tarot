#include "Trefle.h"

Trefle::Trefle():AForme(0, "Trefle", 0)
{

}

bool Trefle::operator== (const ACarte* carte) const {
    const Trefle *o = dynamic_cast<const Trefle*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}

