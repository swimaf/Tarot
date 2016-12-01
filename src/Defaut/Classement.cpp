#include "Classement.h"


Classement::Classement(QVector<shared_ptr<Joueur>> joueurs): joueurs(joueurs)
{
}

void Classement::ajouterPoints(shared_ptr<Joueur> joueurs, int points) {
    joueurs->ajouterPoints(points);
}

QVector<shared_ptr<Joueur>> Classement::getClassement() {
    sort(joueurs.begin(), joueurs.end(), compare);
    return joueurs;
}

bool Classement::compare(shared_ptr<Joueur> a, shared_ptr<Joueur> b) {
    return a->getPoints() < b->getPoints();
}
