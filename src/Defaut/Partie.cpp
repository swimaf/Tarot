#include "Partie.h"
#include "Distribuer.h"
#include "Passer.h"
#include "../Fenetre/FenetreJeux.h"
#include "../Defaut/Constantes.h"
#include "../Fenetre/FenetreClassement.h"

shared_ptr<FenetreJeux> Partie::fenetre;


Partie::Partie(shared_ptr<Paquet> paquet, QVector<shared_ptr<Joueur>> joueurs) : paquet(paquet), joueurs(joueurs)
{
    chien = make_shared<Chien>(3 + (Constantes::NB_CARTES-3) % joueurs.size());
    classement = make_shared<Classement>(joueurs);
    donneur = joueurs[0];
    jeux = make_shared<FenetreJeux>();
    Partie::fenetre = jeux;
    shared_ptr<Niveau> niveau = make_shared<Passer>();
    while(niveau != NULL) {
        niveaux.push_back(niveau);
        niveau = niveau->getSuivant();
    }
    jeux->show();
}

shared_ptr<Chien> Partie::getChien() {
    return chien;
}

shared_ptr<Paquet> Partie::getPaquet() {
    return paquet;
}

QVector<shared_ptr<Joueur>> Partie::getJoueurs() {
    return joueurs;
}

void Partie::setEtat(shared_ptr<Etat> e){
    etat = e;
}

void Partie::demarrer() {
    etat->demarrer();
}

void Partie::demarrerHumain(int i) {
    etat->demarrerHumain(i);
}


void Partie::transition() {
    etat->transition();
}

void Partie::setPreneur(shared_ptr<Joueur> p){
    preneur = p;
}

shared_ptr<Joueur> Partie::getPreneur() {
    return preneur;
}

void Partie::setDonneur(shared_ptr<Joueur> d) {
    donneur = d;
}

shared_ptr<Joueur> Partie::getDonneur() {
    return donneur;
}

void Partie::setRoiAppele(shared_ptr<ACarte> carte){
    roiAppele = carte;
}

shared_ptr<ACarte> Partie::getRoiAppele() {
    return roiAppele;
}

void Partie::couperJoueur(int index) {
    rotate(joueurs.begin(),joueurs.begin()+index,joueurs.end());
}

QVector<shared_ptr<Equipe>> Partie::getEquipes() {
    return equipes;
}

void Partie::ajouterEquipe(shared_ptr<Equipe> equipe) {
    equipes.push_back(equipe);
}

void Partie::clearEquipes() {
    equipes = QVector<shared_ptr<Equipe>>();
}

shared_ptr<Classement> Partie::getClassement(){
    return classement;
}

shared_ptr<Niveau> Partie::getEnchere() {
    return enchere;
}

void Partie::setEnchere(shared_ptr<Niveau> e) {
    enchere = e;
}



void Partie::compterPoint() {
    int points = 0;
    for(shared_ptr<Equipe> equipe:equipes) {

        if(equipe->getJoueurs().indexOf(preneur) >= 0) {
            points = equipe->getPoints();
            if(equipe->getNbBouts() == 3) {
                points -= 36;
            }else if(equipe->getNbBouts() == 2) {
                points -= 41;
            }else if(equipe->getNbBouts() == 1) {
                points -= 51;
            }else if(equipe->getNbBouts() == 0) {
                points -= 56;
            }
            if(points > 0) {
                points += 25;
            }
            points = enchere->multiplicateur() * points;

            int nbAdversaire = 0;
            /**On enleve les points au perdants**/
            for(shared_ptr<Equipe> e:equipes) {
                if(e->getJoueurs().indexOf(preneur) < 0) {
                    for(shared_ptr<Joueur> joueur:e->getJoueurs()) {
                        joueur->ajouterPoints(-(points));
                    }
                    nbAdversaire += joueurs.size();
                }
            }
            nbAdversaire -= nbAdversaire == 5 ? equipe->getJoueurs().size()+1 : equipe->getJoueurs().size();
            string affichage = "";
            for(shared_ptr<Joueur> joueur:equipe->getJoueurs()) {
                if(joueur == preneur) {
                    joueur->ajouterPoints(points*nbAdversaire);
                    affichage += joueur->getNom();
                } else {
                    joueur->ajouterPoints(points);
                    affichage += " et son coequipier "+joueur->getNom() + " ont ";
                }
            }
            affichage += points > 0 ? " gagné de " : " chuté de ";
            affichage.append(to_string(points)+ " points");
            fenetre->setText(affichage);
            break;
        }
    }
}


shared_ptr<Equipe> Partie::getEquipeByJoueur(shared_ptr<Joueur> joueur) {
    for(shared_ptr<Equipe> equipe:equipes) {
        if(equipe->getJoueurs().indexOf(joueur) >= 0) {
            return equipe;
        }
    }
    return NULL;
}

void Partie::reunirEquipe(shared_ptr<Joueur> deuxiemeMembre){
    shared_ptr<Equipe> equipePreneur = getEquipeByJoueur(preneur);

    if(deuxiemeMembre != preneur) {
        shared_ptr<Equipe> equipe = getEquipeByJoueur(deuxiemeMembre);
        equipePreneur->joindreEquipe(equipe);
        equipes.remove(equipes.indexOf(equipe));
    }

    QVector<shared_ptr<Equipe>> nouvellesEquipes;
    nouvellesEquipes.push_back(equipePreneur);
    shared_ptr<Equipe> equipeBase = nullptr;

    for(shared_ptr<Equipe> eqp:equipes) {
        if(!(eqp == equipePreneur)) {
            if(equipeBase == nullptr) {
                equipeBase = eqp;
            } else {
                equipeBase->joindreEquipe(eqp);
            }
        }
    }

    nouvellesEquipes.push_back(equipeBase);
    equipes = nouvellesEquipes;
}


shared_ptr<FenetreJeux> Partie::getFenetre() {
    return jeux;
}

QVector<shared_ptr<Niveau>> Partie::getNiveaux() {
    return niveaux;
}

shared_ptr<ACarte> Partie::getCarteSelectionne() {
    return carteSelectionne;
}

void Partie::setCarteSelectionne(shared_ptr<ACarte> carte) {
    carteSelectionne = carte;
}

void Partie::choixEnchere(int carte) {
    etat->choixEnchere(carte);
}

void Partie::continuer() {
    etat->continuer();
}
