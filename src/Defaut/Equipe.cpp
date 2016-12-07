#include "Equipe.h"

Equipe::Equipe(QVector<shared_ptr<Joueur>> joueur) : points(0), nbBouts(0), joueurs(joueur)
{}

Equipe::Equipe(shared_ptr<Joueur> joueur) : points(0), nbBouts(0)
{
    joueurs.push_back(joueur);
}


QVector<shared_ptr<Joueur>> Equipe::getJoueurs() {
    return joueurs;
}


void Equipe::ajouterPoints(double p) {
    points += p;
}

double Equipe::getPoints() {
    return points;
}

int Equipe::getNbBouts() {
    return nbBouts;
}

void Equipe::setNbBouts(int nb) {
    nbBouts = nb;
}

void Equipe::ajouterBout(int nb) {
    nbBouts += nb;
}


void Equipe::joindreEquipe(shared_ptr<Equipe> equipe){
    points += equipe->getPoints();
    nbBouts += equipe->getNbBouts();
    for(shared_ptr<Joueur> joueur:equipe->getJoueurs()){
        joueurs.push_back(joueur);
    }
}

bool Equipe::operator== (Equipe* equipe) {
    for(shared_ptr<Joueur> joueur : equipe->getJoueurs()) {
        for(shared_ptr<Joueur> j : joueurs) {
            if(!(j->operator ==(joueur.get()))) {
                return false;
            }
        }
    }
    return true;
}
