#include "LePetit.h"

LePetit::LePetit() : Atout(1)
{

}

double LePetit::getValeur() {
    return 4.5;
}

bool LePetit::isBout(){
    return true;
}


bool LePetit::operator== (const ACarte* carte) const {
    const LePetit *o = dynamic_cast<const LePetit*>(carte);
    if(o == NULL) return false;
    return afficher().compare(o->afficher()) == 0;
}
