#include "FenetreJeux.h"
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <string>
#include "../Defaut/Passer.h"
#include "../Defaut/Partie.h"
#include <QLabel>



FenetreJeux::FenetreJeux(QWidget *parent) : QMainWindow(parent)
{
    QDesktopWidget wid;
    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();
    j = 0;
    QWidget* window = new QWidget();

    gridLayout = new QGridLayout();

    enchere = new QHBoxLayout();
    milieu = new QHBoxLayout();
    chien = make_shared<QHBoxLayout>();
    centre = new QGridLayout();


    continuer = new QPushButton("Continuer");
    continuer->setStyleSheet("max-width: 100px; border-radius:3px; padding:5px;background:white;");
    valider = new QPushButton("Valider");
    valider->setStyleSheet("max-width: 100px;  border-radius:3px; padding:5px; background:white;");
    valider->setVisible(false);
    continuer->setVisible(false);
    connect(valider, SIGNAL(clicked()),this, SLOT(onValider()));
    connect(continuer, SIGNAL(clicked()),this, SLOT(onContinuer()));

    label = new QLabel();

    centre->addLayout(milieu,2,2,1,1);
    milieu->setAlignment(Qt::AlignCenter);
    milieu->addWidget(label);
    milieu->addLayout(enchere);
    milieu->addLayout(chien.get());

    gridLayout->addLayout(centre, 1,1, 3 , 3);

    window->setLayout(gridLayout);
    setFixedHeight(screenHeight-80);
    setFixedWidth(screenWidth);
    setCentralWidget(window);
    setStyleSheet("background : #007614;");
    showNormal();

}

void FenetreJeux::initialisation(shared_ptr<Partie> part) {
    partie = part;
    partie->getChien()->setLayout(chien);
    int taille = partie->getJoueurs().size();


    placement.push_back(make_shared<QVBoxLayout>());
    gridLayout->addLayout(placement.at(0).get(), 1,0, 4 , 1);
    initEmplacement(2,0);

    if(taille == 4) {
        placement.push_back(make_shared<QHBoxLayout>());
        gridLayout->addLayout(placement.at(1).get(), 0,0, 1 , 5);
        initEmplacement(0,2);

    } else if(taille == 5) {
        placement.push_back(make_shared<QHBoxLayout>());
        placement.push_back(make_shared<QHBoxLayout>());
        gridLayout->addLayout(placement.at(1).get(), 0,0, 1 , 2);
        gridLayout->addLayout(placement.at(2).get(), 0,3, 1 , 2);
        initEmplacement(0,1);
        initEmplacement(0,3);

    }

    placement.push_back(make_shared<QVBoxLayout>());
    placement.push_back(make_shared<QHBoxLayout>());
    gridLayout->addLayout(placement.at(placement.size()-2).get(), 1,4, 4 , 1);
    gridLayout->addLayout(placement.at(placement.size()-1).get(), 4,1, 1 , 3);

    initEmplacement(2,4);
    initEmplacement(4,2);

    for(int i=0; i<taille; i++) {
        associerEmplacement(partie->getJoueurs()[i], i, taille);
    }
    createEnchere(partie->getJoueurs().last());

}


void FenetreJeux::ajouterAction(QPushButton *button) {
    connect(button, SIGNAL(clicked()),this, SLOT(pushButtonClicked()));
}

void FenetreJeux::ajouterActionRoi(QPushButton *button) {
    connect(button, SIGNAL(clicked()),this, SLOT(onClickRoi()));
}

void FenetreJeux::pushButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int indexCarte = joueur->getEmplacement()->indexOf(button);
    partie->demarrerHumain(indexCarte);

}

void FenetreJeux::onContinuer() {
    continuer->setVisible(false);
    partie->continuer();
}

void FenetreJeux::onClickRoi() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int indexCarte = joueur->getBoutons()->indexOf(button);
    partie->demarrerHumain(indexCarte-3);
}

void FenetreJeux::eraseRois() {
    delete joueur->getBoutons()->itemAt(3)->widget();
    delete joueur->getBoutons()->itemAt(3)->widget();
    delete joueur->getBoutons()->itemAt(3)->widget();
    delete joueur->getBoutons()->itemAt(3)->widget();
}


void FenetreJeux::initEmplacement(int x, int y) {
    shared_ptr<QHBoxLayout> layout = make_shared<QHBoxLayout>();
    emplacements.push_back(layout);
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
    shared_ptr<QBoxLayout> layout;
    shared_ptr<QHBoxLayout> boutons;
    if(taille == 5) {
        layout = placement.at(indexJoueur);
        boutons = emplacements.at(indexJoueur);
    } else {
        if(indexJoueur == 0) {
            layout = placement.at(indexJoueur);
            boutons = emplacements.at(0);
        } else {
            layout = placement.at(placement.size()+indexJoueur-taille);
            boutons = emplacements.at(placement.size()+indexJoueur-taille);
        }
    }
    if(indexJoueur == 0) {
        centre->addWidget(joueur->ajouterLabel(),3,0,1,1);
    } else if(taille-1 == indexJoueur) {
        QLabel* label = joueur->ajouterLabel();
        label->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
        centre->addWidget(label,3,2,1,1);
    } else if(taille-2 == indexJoueur) {
        centre->addWidget(joueur->ajouterLabel(),3,4,1,1);
    } else if(taille == 4 && indexJoueur == 1) {
        centre->addWidget(joueur->ajouterLabel(),1,2,1,1);
    } else if(taille == 5 && indexJoueur == 1){
        centre->addWidget(joueur->ajouterLabel(),1,1,1,1);
    } else if(taille == 5 && indexJoueur == 2) {
        centre->addWidget(joueur->ajouterLabel(),1,3,1,1);
    }

    joueur->setEmplacement(layout);
    joueur->setBoutons(boutons);



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
        bouton->setStyleSheet("max-width: 100px; border-radius:3px; padding:5px; background:white;");
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

void FenetreJeux::showRoi(shared_ptr<ACarte> roi) {
    QPushButton *bouton = new QPushButton("");
    bouton->setStyleSheet("height:100%;"
                          "width:100%;"
                          "max-height: 100%;"
                          "max-width: 70%;"
                          "border-image :  url(../Tarot/img/cards/"+QString::fromStdString(roi->getURL())+".png) 0 0 0 0 stretch stretch;");
    milieu->addWidget(bouton);
}

void FenetreJeux::eraseRoi() {
    delete milieu->itemAt(milieu->count()-1)->widget();
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

void FenetreJeux::setText(string text) {
    label->setText(QString::fromStdString(text));
}
