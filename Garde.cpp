#include "Garde.h"

Garde::Garde() : Niveau()
{

}

shared_ptr<Niveau> Garde::getSuivant() {
    return NULL;
}

int Garde::getCoefficient() {
    return 2;//A Redefinir;
}


string Garde::getNom() {
    return "Garde";
}

int Garde::seuil() {
    return 105;
}
