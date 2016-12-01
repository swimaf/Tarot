#include "Joueur.h"
#include <QCoreApplication>
#include <iostream>
#include "Constantes.h"
#include "../Carte/Excuse.h"
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



string Joueur::getNom() const {
    return name;
}
void Joueur::clearCartes() {
    jeux = QVector<shared_ptr<ACarte>>();
    QLayoutItem *child;
    while ((child = emplacement->takeAt(0)) != 0)  {
        delete child->widget();
    }
}

void Joueur::removeCarte(shared_ptr<ACarte> carte) {
    int index = jeux.indexOf(carte);
    cerr << index;
    jeux.remove(index);
    delete emplacement->takeAt(index)->widget();
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

void Joueur::setEmplacement(shared_ptr<QBoxLayout> e) {
    emplacement = e;
}

shared_ptr<QBoxLayout> Joueur::getEmplacement() {
    return emplacement;
}


void Joueur::setBoutons(shared_ptr<QHBoxLayout> e) {
    action = e;
}

shared_ptr<QHBoxLayout> Joueur::getBoutons() {
    return action;
}


void Joueur::jouerCarte(shared_ptr<ACarte> carte) {
    int index = jeux.indexOf(carte);
    QWidget *button = emplacement->itemAt(index)->widget();
    emplacement->removeWidget(button);
    action->itemAt(0)->widget()->setVisible(false);
    action->insertWidget(1, button);
}

void Joueur::resetEmplacement() {
    action->itemAt(0)->widget()->setVisible(true);
    delete action->itemAt(1)->widget();
}
