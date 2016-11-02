#include "Enchere.h"
#include <QCoreApplication>
#include <iostream>
#include "Passer.h"
#include "Distribuer.h"
#include "AppelRoi.h"
#include "CreationChien.h"

Enchere::Enchere(shared_ptr<Partie> partie) : Etat(partie)
{}


void Enchere::demarrer() {
    cerr << "\n############# ENCHERE DU JEUX ###########\n" <<endl;
    shared_ptr<Niveau> niveau = make_shared<Passer>();

    for(shared_ptr<Joueur> joueur: partie->getJoueurs()) {
        cerr << "### " << joueur->getNom() << " #### :" ;
        if(joueur->choixEnchere(&partie, &niveau)) {
            partie->setPreneur(joueur);
            if(niveau->getSuivant() == NULL) {
                break;
            }
        }
        cerr << niveau->getNom() << endl;

    }

    if(partie->getPreneur() == NULL) {
        cerr << "Il y a pas de preneur le jeux va être redistribué" << endl;
        recupererCarteSurTable();
        partie->setEtat(make_shared<Distribuer>(partie));

    } else {
        creerEquipes();
        cerr << partie->getPreneur()->getNom() << " fait une " << niveau->getNom() << endl;
        partie->setEnchere(niveau);
        if(partie->getJoueurs().size() == 5) {
            partie->setEtat(make_shared<AppelRoi>(partie));
        } else {
            partie->setEtat(make_shared<CreationChien>(partie));
        }
    }

}

void Enchere::recupererCarteSurTable() {

    for(shared_ptr<Joueur> joueur:partie->getJoueurs()) {
        partie->getPaquet()->ajouterCartes(joueur->getJeux());
        joueur->clearCartes();
    }

    partie->getPaquet()->ajouterCartes(partie->getChien()->getCartes());

    partie->getChien()->clearCartes();

}

void Enchere::creerEquipes() {
    if(partie->getJoueurs().size() == 5) {
        for(shared_ptr<Joueur> joueur: partie->getJoueurs()) {
            partie->ajouterEquipe(make_shared<Equipe>(joueur));
        }
    } else {
        QVector<shared_ptr<Joueur>> js(partie->getJoueurs());
        js.remove(js.indexOf(partie->getPreneur()));
        partie->ajouterEquipe(make_shared<Equipe>(partie->getPreneur()));
        partie->ajouterEquipe(make_shared<Equipe>(js));
    }
}
