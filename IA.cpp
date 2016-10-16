#include "IA.h"

IA::IA(string name): Joueur(name)
{

}


string IA::toString(){
    return "Je suis un IA et je m'apelle' " + name;
}

bool IA::choixEnchere(shared_ptr<Partie> partie, shared_ptr<Niveau> *niveau) {
    return false;  //A redefinir;
}

shared_ptr<ACarte> IA::appelerRoi() {
    return NULL; // A REDEFINIR
}
