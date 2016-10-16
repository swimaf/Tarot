#include "Joueur.h"

Joueur::Joueur(string n) : name(n){
}

string Joueur::toString(){
    return "Je suis un joueur et je m'apelle' " + name;
}

vector<shared_ptr<ACarte>> Joueur::getJeux() {
    return jeux;
}

void Joueur::ajouterCarte(shared_ptr<ACarte> carte) {
    jeux.push_back(carte);
}
string Joueur::getNom() {
    return name;
}
void Joueur::clearCartes() {
    jeux = vector<shared_ptr<ACarte>>();
}
