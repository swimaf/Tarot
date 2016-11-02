#include "Garde.h"

Garde::Garde() : Niveau()
{

}

shared_ptr<Niveau> Garde::getSuivant() {
    return NULL;
}

int Garde::multiplicateur() {
    return 2;
}


string Garde::getNom() {
    return "Garde";
}

int Garde::seuil() {
    return 105;
}
