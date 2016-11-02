#include "Humain.h"
#include <QCoreApplication>
#include <iostream>
#include "Passer.h"
#include "AForme.h"
#include "Atout.h"
#include "Excuse.h"
#include "Coeur.h"
#include "Trefle.h"
#include "Pique.h"
#include "Carreau.h"
#include <algorithm>
#include "Filtre.h"
#include "Constantes.h"
#include "Pli.h"


Humain::Humain(std::string n) : Joueur(n)
{
}

string Humain::toString() {
    return "Je suis un humain et je m'appelle "+Joueur::name;
}

bool Humain::choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Niveau> *niveau) {

    QVector<shared_ptr<Niveau>> vNiveau;
    vNiveau.push_back(make_shared<Passer>());

    cerr << "VOS CARTES : " << endl;
    for(shared_ptr<ACarte> carte:jeux) {
        cerr << carte->afficher() << ", ";
    }

    cerr << "\n\nVOTRE CHOIX : \n0) " << vNiveau[0]->getNom() << endl;

    vNiveau.push_back(niveau->get()->getSuivant());
    int i= 1;
    while(vNiveau[i] != NULL) {
        cerr << i << ") " << vNiveau[i]->getNom() << endl;
        vNiveau.push_back(vNiveau[i]->getSuivant());
        i++;
    }
    string stringUtilisateur;
    cin >> stringUtilisateur;
    int choixUtilisateur = stoi(stringUtilisateur);
    if(choixUtilisateur > 0) {
        niveau->operator =(vNiveau[choixUtilisateur]);
        cerr << "Vous avec choisie : " << niveau->get()->getNom() << endl;
    }
    return choixUtilisateur > 0;
}


shared_ptr<ACarte> Humain::appelerRoi(QVector<shared_ptr<ACarte>> rois) {

    cerr << "Choisir votre roi :" << endl;
    int i=0;
    for(shared_ptr<ACarte> roi : rois) {
        cerr << i<< ") "<< roi->afficher() << endl;
        i++;
    }
    string stream;
    cin >> stream;
    shared_ptr<ACarte> roiAppele = rois[stoi(stream)];
    cerr << "Vous avez choisie le :" + roiAppele->afficher() << endl;

    return roiAppele;
}

QVector<shared_ptr<ACarte>> Humain::selectionCartesChien(int taille) {
    QVector<int> element;
    cerr << "VOS CARTES :" << endl;
    for(shared_ptr<ACarte> carte:jeux) {
        cerr << carte->afficher() << ", ";
    }

    QVector<shared_ptr<ACarte>> carteJouable (jeux.size());
    auto it = copy_if (jeux.begin(), jeux.end(), carteJouable.begin(), [](shared_ptr<ACarte> carte){
            return !(carte->isAtout() || carte->isRoi() || carte->isBout());
    });
    carteJouable.resize(distance(carteJouable.begin(),it));

    unsigned int i=0;
    cerr << "\n\nVOTRE CHOIX :" << endl;
    for(shared_ptr<ACarte> carte:carteJouable) {
        cerr << " "<<i << ") "+carte->afficher() << endl;
        i++;
    }


    string stream;
    int index;
    i = 1;
    while(element.size() != taille) {
        cerr << i << " cartes :" << endl;
        cin >> stream;
        index = stoi(stream);
        if(index < carteJouable.size() && find(element.begin(), element.end(), index) == element.end()) {
            element.push_back(index);
            i++;
        } else {
            cerr << "Cette carte à déjà été choisie :" << endl;
        }
    }
    QVector<shared_ptr<ACarte>> cartes;
    for(int i = 0; i<taille; i++) {
        cartes.push_back(carteJouable[element[i]]);
    }

    return cartes;
}


void Humain::trierJeux() {
    QVector<QVector<shared_ptr<ACarte>>> formes;
    formes.push_back(Filtre<Trefle, ACarte>::filtreClass(jeux, true));
    formes.push_back(Filtre<Pique, ACarte>::filtreClass(jeux, true));
    formes.push_back(Filtre<Coeur, ACarte>::filtreClass(jeux, true));
    formes.push_back(Filtre<Carreau, ACarte>::filtreClass(jeux, true));

    sort(formes.begin(), formes.end(), Constantes::compare);

    formes.push_back(Filtre<Atout, ACarte>::filtreClass(jeux, true));
    formes.push_back(Filtre<Excuse, ACarte>::filtreClass(jeux, true));
    clearCartes();
    for(QVector<shared_ptr<ACarte>> type : formes) {
        sort(type.begin(), type.end(), Constantes::sortJeux);
        for(shared_ptr<ACarte> carte : type) {
            jeux.push_back(carte);
        }
    }
}

shared_ptr<ACarte> Humain::selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie) {

    cerr << "\n**** "<< name << " : Humain *****" << endl;

    cerr << "\nVOS CARTES" << endl;
    for(shared_ptr<ACarte> carte : jeux) {
        cerr << carte->afficher() << ", ";
    }

    cerr << "\n\nVOUS POUVEZ JOUER" << endl;

    QVector<shared_ptr<ACarte>> cartes = getCartesJouable(pli);
    int i = 0;
    for(shared_ptr<ACarte> carte : cartes) {
        cerr << i << ") "<<carte->afficher() << endl;
        i++;
    }

    int choix = -1;
    while(choix < 0 || choix >= i) {
        cerr << "\nVOTRE CHOIX : " << endl;
        string t; /**A MODIFIER**/
        cin >> t;
        choix = stoi(t);
    }

    return cartes[choix];
}

