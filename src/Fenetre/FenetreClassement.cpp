#include "FenetreClassement.h"
#include <QGridLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QCoreApplication>
#include <iostream>
#include "../Defaut/Partie.h"

FenetreClassement::FenetreClassement(QWidget *parent) : QMainWindow(parent)
{
    QWidget* window = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    window->setLayout(layout);
    setFixedWidth(340);
    setFixedHeight(300);

    setCentralWidget(window);
    QPushButton* continuer = new QPushButton("Nouvelle manche");
    continuer->setStyleSheet("border-radius:3px; background-color:green;color:white;padding:5px;");
    QPushButton* quitter = new QPushButton("Quitter");
    quitter->setStyleSheet("border-radius:3px; background-color:red;color:white;padding:5px;");

    connect(quitter, SIGNAL(clicked()),this, SLOT(onQuitter()));
    connect(continuer, SIGNAL(clicked()),this, SLOT(onContinuer()));

    tableWidget = new QTableWidget();
    tableWidget->setColumnCount(3);
    tableHeader <<"Nom"<<"Points" << "Type";
    tableWidget->setHorizontalHeaderLabels(tableHeader);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    layout->addWidget(tableWidget);
    layout->addWidget(continuer);
    layout->addWidget(quitter);

    setWindowTitle("Classement de la partie");
}

void FenetreClassement::updateAndShow(QVector<shared_ptr<Joueur>> joueurs) {
    int i = 0;
    tableWidget->clear();
    tableWidget->setRowCount(joueurs.size());

    for(shared_ptr<Joueur> joueur:joueurs) {
        tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(joueur->getNom())));
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(joueur->getPoints())));
        tableWidget->setItem(i, 2, new QTableWidgetItem(joueur->getType()));
        cerr << joueur->getPoints();
        i++;
    }
    show();
}


void FenetreClassement::onQuitter(){
    exit(0);
}

void FenetreClassement::onContinuer() {
    Partie::fenetre->onContinuer();
    hide();
}
