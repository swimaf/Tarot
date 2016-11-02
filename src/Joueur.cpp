#include "Joueur.h"
#include <QCoreApplication>
#include <iostream>
#include "Constantes.h"
#include "Excuse.h"
#include "Equipe.h"
#include "Partie.h"

Joueur::Joueur(string n) : name(n), points(0){
}

string Joueur::toString(){
    return "Je suis un joueur et je m'apelle' " + name;
}

QVector<shared_ptr<ACarte>> Joueur::getJeux() {
    return jeux;
}

void Joueur::ajouterCarte(shared_ptr<ACarte> carte) {
    jeux.push_back(carte);
}
string Joueur::getNom() const {
    return name;
}
void Joueur::clearCartes() {
    jeux = QVector<shared_ptr<ACarte>>();
}

void Joueur::removeCarte(shared_ptr<ACarte> carte) {
    jeux.erase(jeux.begin() + jeux.indexOf(carte));
}

void Joueur::trierJeux() {}


int Joueur::getPoints(){
    return points;
}

void Joueur::ajouterPoints(int point){
    points+=point;
}

bool Joueur::operator== (const Joueur* joueur) const {
    return name.compare(joueur->getNom()) == 0;
}



QVector<shared_ptr<ACarte>> Joueur::getCartesJouable(Pli *pli) {
    if(pli->getCartes().isEmpty()) {
        return jeux;
    }

    shared_ptr<ACarte> carteBase = pli->getBase();
    QVector<shared_ptr<ACarte>> cartes;
    if(carteBase->getType().compare("Atout") != 0) {
        cartes = ACarte::filtre(carteBase->getType(), jeux);
    }
    if(cartes.isEmpty()) {
        cartes = ACarte::filtre("Atout", jeux);
        if(cartes.isEmpty()) {
            cartes.clear();
            copy(jeux.begin(), jeux.end(), back_inserter(cartes));
        } else {
            int joueur = pli->indexOfVainqueur();
            QVector<shared_ptr<ACarte>> cartesAtouts = ACarte::filtreByValue(pli->getCarte(joueur)->poids(),cartes);
            if(!cartesAtouts.isEmpty()) {
                cartes = cartesAtouts;
            }
        }
    }

    QVector<shared_ptr<ACarte>> excuse =  ACarte::filtre("Excuse", jeux);
    copy(excuse.begin(), excuse.end(), back_inserter(cartes));
    sort(cartes.begin(), cartes.end(), Constantes::sortJeux);
    return cartes;
}

