#include "Prise.h"
#include "Garde.h"

Prise::Prise() : Niveau()
{

}

shared_ptr<Niveau> Prise::getSuivant() {
    return make_shared<Garde>();
}

int Prise::getCoefficient() {
    return 2;//A Redefinir;
}

string Prise::getNom() {
    return "Prise";
}

int Prise::seuil(){
    return 95;
}
