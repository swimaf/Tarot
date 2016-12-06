#include "Humain.h"
#include "Partie.h"
#include "Filtre.h"
#include "../Carte/Trefle.h"
#include "../Carte/Carreau.h"
#include "../Carte/Coeur.h"
#include "../Carte/Pique.h"
#include "../Carte/Atout.h"
#include "../Carte/Excuse.h"
#include "Constantes.h"

Humain::Humain()
{

}

bool Humain::choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur){
    int index = partie->get()->getNiveaux().indexOf(partie->get()->getEnchere());
    partie->get()->getFenetre()->checkEnchere(index, true);
    return false;
}

shared_ptr<ACarte> Humain::appelerRoi(QVector<shared_ptr<ACarte>> rois, shared_ptr<Joueur> joueur){

    for(shared_ptr<ACarte> roi:rois) {
        QPushButton *bouton = new QPushButton("");
        bouton->setStyleSheet("height:100%;"
                              "width:100%;"
                              "max-height: 100%;"
                              "max-width: 70%;"
                              "border-image :  url(../Tarot/img/cards/"+QString::fromStdString(roi->getURL())+".png) 0 0 0 0 stretch stretch;");
//        action->addWidget(bouton);
        joueur.get()->addWidgetToAction(bouton);
        Partie::fenetre->ajouterActionRoi(bouton);
    }
    return NULL;
}

QVector<shared_ptr<ACarte>> Humain::selectionCartesChien(int taille, shared_ptr<Joueur> joueur){
    QVector<shared_ptr<ACarte>> cartes;
    return cartes;
}

void Humain::selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur){
    joueur.get()->setSelectable(joueur.get()->getCartesJouable(pli));
    QString style;
    QWidget* c;
    for(shared_ptr<ACarte> carte : joueur.get()->getSelectable()) {
        c = joueur.get()->getEmplacement()->itemAt(joueur.get()->getJeux().indexOf(carte))->widget();
        style = c->styleSheet();
        c->setStyleSheet(style+QString::fromStdString("background-color:red;"));
    }
}

bool Humain::isHumain(){
    return true;
}

void Humain::ajouterCarte(shared_ptr<ACarte> carte, shared_ptr<Joueur> joueur){
    QPushButton *bouton = new QPushButton("");
    bouton->setStyleSheet("height:100%;"
                          "width:100%;"
                          "max-height: 100%;"
                          "max-width: 70%;"
                          "border-image :  url('../Tarot/img/cards/"+QString::fromStdString(carte->getURL())+".png') 0 0 0 0 stretch stretch;");
    joueur.get()->addWidgetToEmplacement(bouton);
    Partie::fenetre->ajouterAction(bouton);
    joueur.get()->getJeux().push_back(carte);
}

QString Humain::getType() {
    return "Humain";
}

void Humain::trierJeux(shared_ptr<Joueur> joueur) {
    QVector<QVector<shared_ptr<ACarte>>> formes;
    formes.push_back(Filtre<Trefle, ACarte>::filtreClass(joueur.get()->getJeux(), true));
    formes.push_back(Filtre<Pique, ACarte>::filtreClass(joueur.get()->getJeux(), true));
    formes.push_back(Filtre<Coeur, ACarte>::filtreClass(joueur.get()->getJeux(), true));
    formes.push_back(Filtre<Carreau, ACarte>::filtreClass(joueur.get()->getJeux(), true));

    sort(formes.begin(), formes.end(), Constantes::compare);

    formes.push_back(Filtre<Atout, ACarte>::filtreClass(joueur.get()->getJeux(), true));
    formes.push_back(Filtre<Excuse, ACarte>::filtreClass(joueur.get()->getJeux(), true));
    joueur.get()->clearCartes();
    for(QVector<shared_ptr<ACarte>> type : formes) {
        sort(type.begin(), type.end(), Constantes::sortJeux);
        for(shared_ptr<ACarte> carte : type) {
            joueur.get()->ajouterCarte(carte);
        }
    }
}
