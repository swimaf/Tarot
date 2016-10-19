#include "Atout.h"


Atout::Atout(string name) : ACarte(name)
{}

string Atout::afficher() const{
    return ACarte::afficher()+ " d'Atout";
}

double Atout::getValeur() {
    return 0.5;
}


bool Atout::isBout(){
    return false;
}

bool Atout::isAtout(){
    return true;
}

bool Atout::operator== (const ACarte* carte) const {
    const Atout *o = dynamic_cast<const Atout*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}
