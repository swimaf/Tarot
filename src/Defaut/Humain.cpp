#include "Humain.h"
#include <QCoreApplication>
#include <iostream>
#include "Passer.h"
#include "../Carte/AForme.h"
#include "../Carte/Atout.h"
#include "../Carte/Excuse.h"
#include "../Carte/Coeur.h"
#include "../Carte/Trefle.h"
#include "../Carte/Pique.h"
#include "../Carte/Carreau.h"
#include <algorithm>
#include "Filtre.h"
#include "Constantes.h"
#include "Pli.h"
#include "Partie.h"


Humain::Humain(std::string n) : Joueur(n)
{
}

string Humain::toString() {
    return "Je suis un humain et je m'appelle "+Joueur::name;
}

bool Humain::choixEnchere(shared_ptr<Partie> *partie) {

    int index = partie->get()->getNiveaux().indexOf(partie->get()->getEnchere());
    partie->get()->getFenetre()->checkEnchere(index, true);
    return false;
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
    QVector<shared_ptr<ACarte>> cartes;
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
            ajouterCarte(carte);
        }
    }
}

void Humain::selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie) {

    /*cerr << "\n**** "<< name << " : Humain *****" << endl;

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
        string t; /**A MODIFIER*
        cin >> t;
        choix = stoi(t);
    }*/

}

void Humain::ajouterCarte(shared_ptr<ACarte> carte) {
    QPushButton *bouton = new QPushButton("");
    bouton->setStyleSheet("height:100%;"
                          "width:100%;"
                          "max-height: 100%;"
                          "max-width: 70%;"
                          "border-image :  url('/home/martinet/Documents/L3/Pattern/Projet/tarot/img/cards/"+QString::fromStdString(carte->getURL())+".png');");
    emplacement->addWidget(bouton);
    Partie::fenetre->ajouterAction(bouton);
    jeux.push_back(carte);
}


bool Humain::isHumain() {
    return true;
}

