#include "FenetreParametre.h"
#include <QWidget>
#include <QComboBox>
#include <QFormLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "../Defaut/Jeu.h"


FenetreParametre::FenetreParametre(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget* window = new QWidget();
    nombreJoueurs = new QComboBox();
    for (int i = 3; i <= 5; ++i) {
        nombreJoueurs->addItem(QString::number(i));
    }
    QLabel* titre = new QLabel("Bienvenue sur le Tarot");
    titre->setStyleSheet("font-size:25px");
    titre->setAlignment(Qt::AlignHCenter);
    QLabel* titre2 = new QLabel("Selectionner le nombre de joueurs");
    titre2->setStyleSheet("font-size:15px; font-style:italic;");
    titre2->setAlignment(Qt::AlignHCenter);


    QPushButton *valider = new QPushButton("Valider");
    valider->setStyleSheet("background-color:green; border-radius:3px;color:white;padding:5px;");
    QPushButton *quitter = new QPushButton("Quitter");
    quitter->setStyleSheet("background-color:red; border-radius:3px;color:white; padding:5px;");
    connect(valider, SIGNAL(clicked()),this, SLOT(onValider()));
    connect(quitter, SIGNAL(clicked()),this, SLOT(close()));

    QVBoxLayout *vBox = new QVBoxLayout();
    window->setLayout(vBox);
    vBox->addWidget(titre);
    vBox->addWidget(titre2);
    vBox->addWidget(nombreJoueurs);
    vBox->addWidget(valider);
    vBox->addWidget(quitter);
    setCentralWidget(window);
    setFixedWidth(350);
    setFixedHeight(250);
    setWindowTitle("Paramètres de la partie");

    show();
}

void FenetreParametre::onValider() {
     Jeu jeu(nombreJoueurs->currentText().toInt());
     jeu.exec();
     close();
}
