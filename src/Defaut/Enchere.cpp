#include "Enchere.h"
#include "Passer.h"
#include "Distribuer.h"
#include "AppelRoi.h"
#include "CreationChien.h"

Enchere::Enchere(shared_ptr<Partie> partie) : Etat(partie)
{}


void Enchere::demarrer() {
    partie->getFenetre()->setText("Vous pouvez encherir : ");
    partie->setEnchere(partie->getNiveaux()[0]);
    for(shared_ptr<Joueur> joueur: partie->getJoueurs()) {
        if(joueur->isHumain()) {
            joueur->choixEnchere(&partie);
            break;
        }
        if(joueur->choixEnchere(&partie)) {
            partie->setPreneur(joueur);
            if(partie->getEnchere()->getSuivant() == NULL) {
                transition();
                break;
            }
        }
        joueur->setText("Choix : " + partie->getEnchere()->getNom());
    }
}

void Enchere::choixEnchere(int i) {
    if(i > 0) {
        partie->setEnchere(partie->getNiveaux()[i]);
        partie->setPreneur(partie->getFenetre()->getHumain());
    }
    partie->getFenetre()->checkEnchere(0, false);

    for(int i = partie->getJoueurs().indexOf(partie->getFenetre()->getHumain())+1; i<partie->getJoueurs().size(); i++) {
        if(partie->getJoueurs()[i]->choixEnchere(&partie)) {
            partie->setPreneur(partie->getJoueurs()[i]);
            if(partie->getEnchere()->getSuivant() == NULL) {
                break;
            }
        }
        partie->getJoueurs()[i]->setText("Choix : " + partie->getEnchere()->getNom());
    }
    transition();

}

void Enchere::transition() {
    for(shared_ptr<Joueur> joueur:partie->getJoueurs()) {
        joueur->setText("");
    }
    if(partie->getPreneur() == NULL) {
        partie->getFenetre()->setText("Il y a pas de preneur le jeux va être redistribué");
        recupererCarteSurTable();
        partie->setEtat(make_shared<Distribuer>(partie));

    } else {
        creerEquipes();
        partie->getFenetre()->setText(partie->getPreneur()->getNom()+ " fait une " +partie->getEnchere()->getNom());
        if(partie->getJoueurs().size() == 5) {
            partie->setEtat(make_shared<AppelRoi>(partie));
        } else {
            partie->setEtat(make_shared<CreationChien>(partie));
        }
    }
    partie->getFenetre()->setVisibleContinuer(true);
}

void Enchere::recupererCarteSurTable() {

    for(shared_ptr<Joueur> joueur:partie->getJoueurs()) {
        partie->getPaquet()->ajouterCartes(joueur->getJeux());
        joueur->clearCartes();
    }

    partie->getPaquet()->ajouterCartes(partie->getChien()->getCartes());
    partie->getChien()->clearCartes(true);

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
