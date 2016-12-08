#include "Atout.h"


Atout::Atout(int poids) : ACarte(0.5,poids, "Atout",to_string(poids))
{}



int Atout::getPoids() const{
    return 100+poids;
}

bool Atout::isAtout() const{
    return true;
}

bool Atout::operator== (const ACarte* carte) const {
    const Atout *o = dynamic_cast<const Atout*>(carte);
    if(o == NULL) return false;
    return getURL().compare(o->getURL()) == 0;
}

string Atout::getURL() const {
    return to_string(poids);
}
