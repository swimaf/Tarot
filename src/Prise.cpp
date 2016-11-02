#include "Prise.h"
#include "Garde.h"

Prise::Prise() : Niveau()
{

}

shared_ptr<Niveau> Prise::getSuivant() {
    return make_shared<Garde>();
}

int Prise::multiplicateur() {
    return 1;
}


string Prise::getNom() {
    return "Prise";
}

int Prise::seuil(){
    return 95;
}
