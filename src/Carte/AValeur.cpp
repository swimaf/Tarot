#include "AValeur.h"

AValeur::AValeur(double valeur, int poids, shared_ptr<AForme> f) : AForme(valeur, "", poids), forme(f)
{
}

string AValeur::getURL() const {
    if(forme == NULL){
        return getURL();
    }
    else {
        return to_string(getPoids())+forme->getURL();
    }
}

string AValeur::getType() const{
    if(forme==NULL)
        return getType();
    else
        return forme->getType();
}





