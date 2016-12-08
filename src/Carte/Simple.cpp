#include "Simple.h"

Simple::Simple(int poids, shared_ptr<AForme> f) : AValeur(0.5, poids, f)
{

}

bool Simple::operator== (const ACarte* carte) const {
    const Simple *o = dynamic_cast<const Simple*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}

string Simple::getName() const{
    return to_string(poids);
}
