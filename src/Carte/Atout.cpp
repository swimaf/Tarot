#include "Atout.h"


Atout::Atout(int val) : val(val)
{}

string Atout::afficher() const{
    return ACarte::afficher()+ " d'Atout";
}

double Atout::getValeur() {
    return 0.5;
}

string Atout::getName() const {
    return to_string(val);
}

int Atout::poids() const{
    return 100+val;
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

string Atout::getType() const{
    return "Atout";
}

string Atout::getURL() const {
    return to_string(val);
}
