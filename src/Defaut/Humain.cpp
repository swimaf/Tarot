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

QString Humain::getType(){
    return "Humain";
}
bool Humain::choixEnchere(shared_ptr<Partie> *partie) {

    int index = partie->get()->getNiveaux().indexOf(partie->get()->getEnchere());
    partie->get()->getFenetre()->checkEnchere(index, true);
    return false;
}


shared_ptr<ACarte> Humain::appelerRoi(QVector<shared_ptr<ACarte>> rois) {

    for(shared_ptr<ACarte> roi:rois) {
        QPushButton *bouton = new QPushButton("");
        bouton->setStyleSheet("height:100%;"
                              "width:100%;"
                              "max-height: 100%;"
                              "max-width: 70%;"
                              "border-image :  url(../tarot/img/cards/"+QString::fromStdString(roi->getURL())+".png) 0 0 0 0 stretch stretch;");
        action->addWidget(bouton);
        Partie::fenetre->ajouterActionRoi(bouton);
    }
    return NULL;
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
    selectable = getCartesJouable(pli);
    QString style;
    QWidget* c;
    for(shared_ptr<ACarte> carte : selectable) {
        c = emplacement->itemAt(jeux.indexOf(carte))->widget();
        style = c->styleSheet();
        c->setStyleSheet(style+QString::fromStdString("background-color:red;"));
    }
}

void Humain::ajouterCarte(shared_ptr<ACarte> carte) {
    QPushButton *bouton = new QPushButton("");
    bouton->setStyleSheet("height:100%;"
                          "width:100%;"
                          "max-height: 100%;"
                          "max-width: 70%;"
                          "border-image :  url(../tarot/img/cards/"+QString::fromStdString(carte->getURL())+".png) 0 0 0 0 stretch stretch;");
    emplacement->addWidget(bouton);
    Partie::fenetre->ajouterAction(bouton);
    jeux.push_back(carte);
}


bool Humain::isHumain() {
    return true;
}


