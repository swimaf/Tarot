#include <QCoreApplication>
#include "Joueur.h"
#include "Humain.h"
#include "ACarte.h"
#include <iostream>
#include <QVector>
#include <memory>
#include "Paquet.h"
#include "Partie.h"
#include "IA.h"
#include "Distribuer.h"

using namespace std;

QVector<shared_ptr<Joueur>> creerJoueur() {
    QVector<shared_ptr<Joueur>> joueurs;
    joueurs.push_back(make_shared<IA>("Etienne"));
    joueurs.push_back(make_shared<IA>("Lea"));
    joueurs.push_back(make_shared<IA>("Simon"));
    joueurs.push_back(make_shared<IA>("Francoise"));
    joueurs.push_back(make_shared<Humain>("Pierre"));

    return joueurs;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<shared_ptr<Joueur>> joueurs = creerJoueur();

    shared_ptr<Paquet> paquet = Paquet::getInstance();
    paquet->melanger();

    shared_ptr<Partie> partie = make_shared<Partie>(paquet, joueurs);
    partie->setEtat(make_shared<Distribuer>(partie->shared_from_this()));

    while(true) {
        partie->demarrer();
    }
    return a.exec();
}

