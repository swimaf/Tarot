#include "Chien.h"
#include <QPushButton>

Chien::Chien(int n) : taille(n)
{

}

void Chien::ajouterCarte(shared_ptr<ACarte> carte) {
    cartes.push_back(carte);
}

int Chien::getTaille(){
    return taille;
}

QVector<shared_ptr<ACarte>> Chien::getCartes() {
    return cartes;
}

void Chien::clearCartes(bool withLayout) {
    cartes = QVector<shared_ptr<ACarte>>();
    if(withLayout) {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != 0)  {
            delete child->widget();
        }
    }
}

void Chien::setCartes(QVector<shared_ptr<ACarte>> c) {
    cartes = c;
}

void Chien::setLayout(shared_ptr<QHBoxLayout> l) {
    layout = l;
}

void Chien::removeCarte(shared_ptr<ACarte> carte) {
    cartes.remove(cartes.indexOf(carte));
}


void Chien::montrerChien() {
    for(shared_ptr<ACarte> carte: cartes) {
        QPushButton *bouton = new QPushButton("");
        bouton->setStyleSheet("height:100%;"
                              "width:100%;"
                              "max-height: 100%;"
                              "max-width: 70%;"
                              "border-image :  url('/home/martinet/Documents/L3/Pattern/Projet/tarot/img/cards/"+QString::fromStdString(carte->getURL())+".png');");
        layout->addWidget(bouton);
    }
}
