#include "Carreau.h"

Carreau::Carreau():AForme(0, "Carreau", 0)
{

}

bool Carreau::operator== (const ACarte* carte) const {
    const Carreau *o = dynamic_cast<const Carreau*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
