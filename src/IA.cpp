#include "IA.h"
#include <QCoreApplication>
#include <iostream>
#include "Constantes.h"
#include <list>
#include <algorithm>
#include "Filtre.h"
#include "Trefle.h"
#include "Carreau.h"
#include "Pique.h"
#include "Coeur.h"
#include "Partie.h"
#include "Atout.h"
#include "Excuse.h"

IA::IA(string name): Joueur(name)
{

}


string IA::toString(){
    return "Je suis un IA et je m'apelle' " + name;
}

bool IA::choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Niveau> *niveau) {


    int nbAtout = ACarte::compterNbAtout(jeux);
    int nbBout = ACarte::compterNbBout(jeux);
    int nbValeurs = ACarte::compterPoint(jeux);

    int nbJoueurs = partie->get()->getJoueurs().size();
    int coeff = nbAtout * Constantes::COEFF_ATOUT + nbBout * Constantes::COEFF_BOUT + nbValeurs*Constantes::COEFF_VALEUR + nbJoueurs*10;

    bool choix= false;
    shared_ptr<Niveau> n = niveau->get()->getSuivant();

    while(n != NULL) {
       if(coeff > n->seuil()) {
           niveau->operator =(n);
           choix = true;
       }
       n = n->getSuivant();
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


shared_ptr<ACarte> IA::selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie) {

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
                return f[0]; // A REDEFINIR
            }
        }
    }

    QVector<shared_ptr<ACarte>> cartes = getCartesJouable(pli);
    return cartes[0];
}
