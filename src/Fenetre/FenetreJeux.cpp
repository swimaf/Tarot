#include "FenetreJeux.h"
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <string>
#include "Sleeper.h"
#include <iostream>
#include <QCoreApplication>
#include "../Defaut/Passer.h"
#include "../Defaut/Partie.h"



FenetreJeux::FenetreJeux(QWidget *parent) : QMainWindow(parent)
{
    QDesktopWidget wid;
    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();
    j = 0;
    QWidget* window = new QWidget();

    QGridLayout *gridLayout = new QGridLayout();

    placement.push_back(make_shared<QVBoxLayout>());
    placement.push_back(make_shared<QHBoxLayout>());
    placement.push_back(make_shared<QVBoxLayout>());
    placement.push_back(make_shared<QHBoxLayout>());

    enchere = new QHBoxLayout();
    milieu = new QHBoxLayout();
    chien = make_shared<QHBoxLayout>();
    centre = new QGridLayout();


    continuer = new QPushButton("Continuer");
    continuer->setStyleSheet("max-width: 100px; background:white;");
    valider = new QPushButton("Valider");
    valider->setStyleSheet("max-width: 100px; background:white;");
    valider->setVisible(false);
    continuer->setVisible(false);
    connect(valider, SIGNAL(clicked()),this, SLOT(onValider()));
    connect(continuer, SIGNAL(clicked()),this, SLOT(onContinuer()));

    initEmplacement(1,0);
    initEmplacement(0,1);
    initEmplacement(1,2);
    initEmplacement(2,1);


    centre->addLayout(milieu,1,1,1,1);
    milieu->addLayout(enchere);
    milieu->addLayout(chien.get());

    gridLayout->addLayout(centre, 1,1, 3 , 3);
    gridLayout->addLayout(placement.at(0).get(), 1,0, 4 , 1);
    gridLayout->addLayout(placement.at(1).get(), 0,0, 1 , 5);
    gridLayout->addLayout(placement.at(2).get(), 1,4, 4 , 1);
    gridLayout->addLayout(placement.at(3).get(), 4,1, 1 , 3);

    window->setLayout(gridLayout);
    setFixedWidth(1000);
    setFixedHeight(700);

    setCentralWidget(window);
    setGeometry((screenWidth/2)-(1000/2),(screenHeight/2)-(700/2),1000,700);
    setStyleSheet("background : #007614;");
    show();

}

void FenetreJeux::ajouterAction(QPushButton *button) {
    connect(button, SIGNAL(clicked()),this, SLOT(pushButtonClicked()));
}

void FenetreJeux::pushButtonClicked() {
    std::cerr << "Salut";
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int indexCarte = joueur->getEmplacement()->indexOf(button);
    partie->demarrerHumain(indexCarte);
}

void FenetreJeux::setPartie(shared_ptr<Partie> part) {
    partie = part;
    partie->getChien()->setLayout(chien);
}

void FenetreJeux::onContinuer() {
    continuer->setVisible(false);
    partie->continuer();
}

void FenetreJeux::initEmplacement(int x, int y) {
    shared_ptr<QHBoxLayout> layout = make_shared<QHBoxLayout>();
    emplacements.push_back(layout);
    //s->setStyleSheet("height:100%;border:0; outline:none");
    QPushButton *r = new QPushButton();
    r->setStyleSheet("max-height: 100%; max-width: 70%; border-radius : 5px; border:2px solid #005E10;");
    layout->addWidget(r);

    centre->addLayout(layout.get(),x,y,1,1);

}

void FenetreJeux::onValider() {
    valider->setVisible(false);
    partie->transition();
}


void FenetreJeux::associerEmplacement(shared_ptr<Joueur> joueur, int indexJoueur, int taille) {
    cerr << emplacements.size();
    if(taille == 5) {
        joueur->setEmplacement(placement.at(indexJoueur));
        joueur->setBoutons(emplacements.at(indexJoueur));
    } else {
        if(indexJoueur == 0) {
            joueur->setEmplacement(placement.at(0));
            joueur->setBoutons(emplacements.at(0));
        } else {
            joueur->setEmplacement(placement.at(placement.size()+indexJoueur-taille));
            joueur->setBoutons(emplacements.at(placement.size()+indexJoueur-taille));
        }
    }
}

void FenetreJeux::checkEnchere(int index, bool visible) {
    enchere->itemAt(0)->widget()->setVisible(visible);

    for (int i = index+1; i < enchere->count(); ++i) {
        QWidget *w = enchere->itemAt(i)->widget();
        if(w != NULL) {
            w->setVisible(visible);
        }
    }
}

void FenetreJeux::createEnchere(shared_ptr<Joueur> j) {
    joueur = j;
    joueur->getBoutons()->addWidget(valider);
    joueur->getBoutons()->addWidget(continuer);

    shared_ptr<Niveau> niveau = make_shared<Passer>();

    while(niveau != NULL) {
        QPushButton *bouton = new QPushButton(QString::fromStdString(niveau->getNom()));
        bouton->setVisible(false);
        enchere->addWidget(bouton);
        niveau = niveau->getSuivant();
        connect(bouton, SIGNAL(clicked()), this, SLOT(enchereClicked()));

    }
}


void FenetreJeux::enchereClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int i = enchere->indexOf(button);
    partie->choixEnchere(i);

}

shared_ptr<Joueur> FenetreJeux::getHumain() {
    return joueur;
}

void FenetreJeux::setVisibleContinuer(bool b) {
    continuer->setVisible(b);
}
void FenetreJeux::setVisibleValider(bool b) {
    valider->setVisible(b);
}
