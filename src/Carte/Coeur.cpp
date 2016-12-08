#include "Coeur.h"

Coeur::Coeur():AForme(0, "Coeur", 0)
{

}

bool Coeur::operator== (const ACarte* carte) const {
    const Coeur *o = dynamic_cast<const Coeur*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}
