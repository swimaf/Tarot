#include "IA.h"
#include <QCoreApplication>
#include <iostream>
#include "Constantes.h"
#include <list>
#include <algorithm>
#include "Filtre.h"
#include "../Carte/Trefle.h"
#include "../Carte/Carreau.h"
#include "../Carte/Pique.h"
#include "../Carte/Coeur.h"
#include "Partie.h"
#include "../Carte/Atout.h"
#include "../Carte/Excuse.h"

IA::IA(string name): Joueur(name)
{

}


string IA::toString(){
    return "Je suis un IA et je m'apelle' " + name;
}

bool IA::choixEnchere(shared_ptr<Partie> *partie) {


    int index       = partie->get()->getNiveaux().indexOf(partie->get()->getEnchere());
    int nbAtout     = ACarte::compterNbAtout(jeux);
    int nbBout      = ACarte::compterNbBout(jeux);
    int nbValeurs   = ACarte::compterPoint(jeux);

    int nbJoueurs = partie->get()->getJoueurs().size();
    int coeff = nbAtout * Constantes::COEFF_ATOUT + nbBout * Constantes::COEFF_BOUT + nbValeurs*Constantes::COEFF_VALEUR + nbJoueurs*10;

    bool choix= false;

    cerr << index <<endl;
    for(int i=partie->get()->getNiveaux().size() - 1; i> index ; i--) {
       if(coeff > partie->get()->getNiveaux()[i]->seuil()) {
           partie->get()->setEnchere(partie->get()->getNiveaux()[i]);
           choix = true;
       }
    }

    //cerr << "Nb joueur" << nbJoueurs <<"Atout : " << nbAtout << " Bout : " << nbBout << " Val : " << nbValeurs << endl;
    return choix;
}


shared_ptr<ACarte> IA::appelerRoi(QVector<shared_ptr<ACarte>> allRois) {

    list<shared_ptr<ACarte>> listRoi;
    copy(allRois.begin(), allRois.end(), back_inserter(listRoi));

    QVector<shared_ptr<ACarte>> rois = ACarte::getRois(jeux);
    cerr << "Possède :" << endl;
    for(shared_ptr<ACarte> roi : rois) {
        cerr << roi->afficher() << endl;
    }

    for(int i=0; i<allRois.size(); ++i) {
        for(shared_ptr<ACarte> roi : rois) {
            if(allRois[i]->equals(roi)) {
                listRoi.remove(allRois[i]);
            }
        }
    }

    cerr << "Peux choisir :" << endl;

    for(shared_ptr<ACarte> roi : listRoi) {
        cerr << roi->afficher() << endl;
    }
    if(listRoi.size() == 0) {
        /** A REDEFINIR CHOISIR LA REINE SI IL A TOUT LES ROIS **/
        return rois[0];
    }
    auto carte = listRoi.begin();
    advance(carte, rand() % listRoi.size());
    return *carte;
}


QVector<shared_ptr<ACarte>> IA::selectionCartesChien(int taille) {
    QVector<shared_ptr<ACarte>> chien;

    QVector<QVector<shared_ptr<ACarte>>> formes;
    formes.push_back(Filtre<Trefle, ACarte>::filtreClass(jeux, false));
    formes.push_back(Filtre<Pique, ACarte>::filtreClass(jeux, false));
    formes.push_back(Filtre<Coeur, ACarte>::filtreClass(jeux, false));
    formes.push_back(Filtre<Carreau, ACarte>::filtreClass(jeux, false));

    sort(formes.begin(), formes.end(), Constantes::compare);

    unsigned int i =0, k =-1;
    while(chien.size() != taille) {
        if(k < formes[i].size()) {
            chien.push_back(formes[i][k]);
            k++;
        } else {
            i++;
            k = 0;
        }
    }

    return chien;
}



void IA::selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie) {

    cerr << "\n**** " << name << " : Intelligence artificielle *****" << endl;

    if(pli->getCartes().isEmpty()) {
        QVector<QVector<shared_ptr<ACarte>>> formes;
        formes.push_back(Filtre<Trefle, ACarte>::filtreClass(jeux, true));
        formes.push_back(Filtre<Pique, ACarte>::filtreClass(jeux, true));
        formes.push_back(Filtre<Coeur, ACarte>::filtreClass(jeux, true));
        formes.push_back(Filtre<Carreau, ACarte>::filtreClass(jeux, true));
        formes.push_back(Filtre<Atout, ACarte>::filtreClass(jeux, true));
        formes.push_back(Filtre<Excuse, ACarte>::filtreClass(jeux, true));

        for(QVector<shared_ptr<ACarte>> f:formes) {
            if(!f.isEmpty()) {
                partie->get()->setCarteSelectionne(f[0]); // A REDEFINIR
                jouerCarte(f[0]);
                break;
            }
        }
    } else {
        QVector<shared_ptr<ACarte>> cartes = getCartesJouable(pli);
        partie->get()->setCarteSelectionne(cartes[0]);
        jouerCarte(cartes[0]);
    }
}

void IA::ajouterCarte(shared_ptr<ACarte> carte) {
    QPushButton *bouton = new QPushButton("");
    bouton->setStyleSheet("height:100%;"
                          "width:100%;"
                          "max-height: 100%;"
                          "max-width: 70%;"
                          "border-image :  url('/home/martinet/Documents/L3/Pattern/Projet/tarot/img/cards/"+QString::fromStdString(carte->getURL())+".png');");
    emplacement->addWidget(bouton);
    jeux.push_back(carte);
}



bool IA::isHumain() {
    return false;
}
