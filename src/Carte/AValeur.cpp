#include "AValeur.h"

AValeur::AValeur(double valeur, int poids, shared_ptr<AForme> f) : AForme(valeur, "", poids), AForme(f)
{
}

string AValeur::getURL() const {
    if(AForme == NULL){
        return getURL();
    }
    else {
        return to_string(getPoids())+AForme->getURL();
    }
}

string AValeur::getType() const{
    if(AForme==NULL)
        return getType();
    else
        return AForme->getType();
}





