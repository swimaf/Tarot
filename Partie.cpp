#include "Partie.h"
#include "Distribuer.h"

Partie::Partie(shared_ptr<Paquet> paquet, vector<shared_ptr<Joueur>> joueurs) : paquet(paquet), joueurs(joueurs)
{
    chien = make_shared<Chien>();
}

shared_ptr<Chien> Partie::getChien() {
    return chien;
}

shared_ptr<Paquet> Partie::getPaquet() {
    return paquet;
}

vector<shared_ptr<Joueur>> Partie::getJoueurs() {
    return joueurs;
}

void Partie::setEtat(shared_ptr<Etat> e){
    etat = e;
}

void Partie::demarrer() {
    etat->demarrer();
}

void Partie::setPreneur(shared_ptr<Joueur> p){
    preneur = p;
}

shared_ptr<Joueur> Partie::getPreneur() {
    return preneur;
}

void Partie::setRoiAppele(shared_ptr<ACarte> carte){
    roiAppele = carte;
}

shared_ptr<ACarte> Partie::getRoiAppele() {
    return roiAppele;
}
