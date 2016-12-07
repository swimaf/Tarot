#include "Jeu.h"
#include "Distribuer.h"
#include "Paquet.h"
#include <QTimer>
#include "Humain.h"
#include "IA.h"

Jeu::Jeu(int nbJoueur)
{

    QVector<shared_ptr<Joueur>> joueurs = creerJoueur(nbJoueur);

    shared_ptr<Paquet> paquet = Paquet::getInstance();
    paquet->melanger();

    partie = make_shared<Partie>(paquet, joueurs);
    partie->setEtat(make_shared<Distribuer>(partie->shared_from_this()));
    partie->getFenetre()->initialisation(partie->shared_from_this());
}

void Jeu::exec() {
    partie->demarrer();
}


QVector<shared_ptr<Joueur>> Jeu::creerJoueur(int nbJoueur) {
    QVector<shared_ptr<Joueur>> joueurs;
    if(nbJoueur > 3) {
        joueurs.push_back(make_shared<Joueur>("Etienne",  make_shared<IA>()));
    }
    if(nbJoueur > 4) {
        joueurs.push_back(make_shared<Joueur>("Lea", make_shared<IA>()));
    }
    joueurs.push_back(make_shared<Joueur>("Francoise",  make_shared<IA>()));
    joueurs.push_back(make_shared<Joueur>("Simon",  make_shared<IA>()));
    joueurs.push_back(make_shared<Joueur>("Pierre", make_shared<Humain>()));

    return joueurs;
}
