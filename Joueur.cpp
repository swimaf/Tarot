#include "Joueur.h"

Joueur::Joueur(std::string n){
    name = n;
}

std::string Joueur::toString(){
    return "Je suis un joueur et je m'apelle' " + name;
}
