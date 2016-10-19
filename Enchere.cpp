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
    cerr << "############# ENCHERE DU JEUX ###########" <<endl;
    int joueurQuiCommence = 0; //A Redefinir plus tard
    shared_ptr<Niveau> niveau = make_shared<Passer>();


    /**A REDEFINIR POUR FAIRE UNE BOUCLE TANT QUE PERSONNE A PRIS ET QU'ON EST ARRIVE AU MAX DES PRISES...*/
    for(shared_ptr<Joueur> joueur: partie->getJoueurs()) {
        if(joueur->choixEnchere(&partie, &niveau)) {
            partie->setPreneur(joueur);
            if(niveau->getSuivant() == NULL) {
                break;
            }
        }
    }

    if(partie->getPreneur() == NULL) {
        cerr << "Il y a pas de preneur le jeux va être redistribuer" << endl;
        recupererCarteSurTable();
        partie->setEtat(make_shared<Distribuer>(partie));

    } else {
        cerr << partie->getPreneur()->getNom() << " fait une " << niveau->getNom() << endl;
        if(partie->getJoueurs().size() == 5) {
            partie->setEtat(make_shared<AppelRoi>(partie));
        } else {
            partie->setEtat(make_shared<CreationChien>(partie));
        }
    }

}

void Enchere::recupererCarteSurTable() {

    for(shared_ptr<Joueur> joueur:partie->getJoueurs()) {
        for(shared_ptr<ACarte> carte:joueur->getJeux()) {
            partie->getPaquet()->ajouterCartes(carte);
        }
        joueur->clearCartes();
    }


    for(shared_ptr<ACarte> carte:partie->getChien()->getCartes()) {
        partie->getPaquet()->ajouterCartes(carte);
    }
    partie->getChien()->clearCartes();

}
