#include "Passer.h"
#include "Prise.h"


Passer::Passer() : Niveau()
{

}

shared_ptr<Niveau> Passer::getSuivant() {
    return make_shared<Prise>();
}

int Passer::multiplicateur() {
    return 0;//A Redefinir;
}

string Passer::getNom() {
    return "Passer";
}

int Passer::seuil(){
    return 0;
}


