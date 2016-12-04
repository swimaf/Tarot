#include "Jeu.h"
#include "Distribuer.h"
#include "Paquet.h"
#include <QTimer>

Jeu::Jeu()
{

    QVector<shared_ptr<Joueur>> joueurs = creerJoueur();

    shared_ptr<Paquet> paquet = Paquet::getInstance();
    paquet->melanger();

    partie = make_shared<Partie>(paquet, joueurs);
    partie->setEtat(make_shared<Distribuer>(partie->shared_from_this()));
    partie->getFenetre()->setPartie(partie->shared_from_this());
}

void Jeu::exec() {
    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(lancer()));
    //timer->start(500);

    //A SUPPRIMER
    //partie->demarrer();
   partie->demarrer();

}

void Jeu::lancer() {
    partie->demarrer();
}


QVector<shared_ptr<Joueur>> Jeu::creerJoueur() {
    QVector<shared_ptr<Joueur>> joueurs;
    joueurs.push_back(make_shared<IA>("Etienne"));
    joueurs.push_back(make_shared<IA>("Lea"));
    joueurs.push_back(make_shared<IA>("Francoise"));
    joueurs.push_back(make_shared<Humain>("Pierre"));

    return joueurs;
}
