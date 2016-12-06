#include "Joueur.h"
#include <QCoreApplication>
#include <iostream>
#include "Constantes.h"
#include "../Carte/Excuse.h"
#include "Equipe.h"
#include "Partie.h"

Joueur::Joueur(string n) : name(n), points(0), humain(new Humain), ia(new IA), strategieCourante(humain){
}


QVector<shared_ptr<ACarte>> Joueur::getJeux() {
    return jeux;
}

string Joueur::getNom() {
    return name;
}
void Joueur::clearCartes() {
    jeux = QVector<shared_ptr<ACarte>>();
    QLayoutItem *child;
    while ((child = emplacement->takeAt(0)) != 0)  {
        delete child->widget();
    }
}

void Joueur::removeSelectable() {
    QString style;
    QWidget* button;
    for(shared_ptr<ACarte> carte:selectable) {
        button = emplacement->itemAt(jeux.indexOf(carte))->widget();
        button->setStyleSheet(button->styleSheet().remove("background-color:red;"));
    }
}


void Joueur::removeCarte(shared_ptr<ACarte> carte, bool removeButton) {
    int index = jeux.indexOf(carte);
    if(removeButton) {
        delete emplacement->takeAt(index)->widget();
    }
    jeux.remove(index);
}

void Joueur::trierJeux() {}


int Joueur::getPoints(){
    return points;
}

void Joueur::ajouterPoints(int point){
    points+=point;
}

bool Joueur::operator== (Joueur* joueur) {
    return name.compare(joueur->getNom()) == 0;
}



QVector<shared_ptr<ACarte>> Joueur::getCartesJouable(Pli *pli) {
    if(pli->getCartes().isEmpty()) {
        return jeux;
    }

    shared_ptr<ACarte> carteBase = pli->getBase();
    QVector<shared_ptr<ACarte>> cartes;
    if(carteBase->getType().compare("Atout") != 0) {
        cartes = ACarte::filtre(carteBase->getType(), jeux);
    }
    if(cartes.isEmpty()) {
        cartes = ACarte::filtre("Atout", jeux);
        if(cartes.isEmpty()) {
            cartes.clear();
            copy(jeux.begin(), jeux.end(), back_inserter(cartes));
        } else {
            int joueur = pli->indexOfVainqueur();
            QVector<shared_ptr<ACarte>> cartesAtouts = ACarte::filtreByValue(pli->getCarte(joueur)->poids(),cartes);
            if(!cartesAtouts.isEmpty()) {
                cartes = cartesAtouts;
            }
        }
    }

    QVector<shared_ptr<ACarte>> excuse =  ACarte::filtre("Excuse", jeux);
    copy(excuse.begin(), excuse.end(), back_inserter(cartes));
    sort(cartes.begin(), cartes.end(), Constantes::sortJeux);
    return cartes;
}

void Joueur::setEmplacement(shared_ptr<QBoxLayout> e) {
    emplacement = e;
}

shared_ptr<QBoxLayout> Joueur::getEmplacement() {
    return emplacement;
}


void Joueur::setBoutons(shared_ptr<QHBoxLayout> e) {
    action = e;
}

shared_ptr<QHBoxLayout> Joueur::getBoutons() {
    return action;
}


void Joueur::jouerCarte(shared_ptr<ACarte> carte) {
    int index = jeux.indexOf(carte);
    QWidget *button = emplacement->itemAt(index)->widget();
    emplacement->removeWidget(button);
    action->itemAt(0)->widget()->setVisible(false);
    action->insertWidget(1, button);
}

void Joueur::resetEmplacement() {
    action->itemAt(0)->widget()->setVisible(true);
    delete action->itemAt(1)->widget();
}

QVector<shared_ptr<ACarte>> Joueur::getSelectable() {
    return selectable;
}

QLabel* Joueur::ajouterLabel() {
    label = new QLabel(QString::fromStdString(name));
    label->setAlignment(Qt::AlignHCenter);
    label->setStyleSheet("color:white");
    return label;
}


void Joueur::setText(string text) {
    label->setText(QString::fromStdString(name+" \n"+text));
}

bool Joueur::choixEnchere(shared_ptr<Partie> *partie){
    return strategieCourante.get()->choixEnchere(*partie, shared_from_this());
}

shared_ptr<ACarte> Joueur::appelerRoi(QVector<shared_ptr<ACarte>> rois){
    return strategieCourante.get()->appelerRoi(rois, shared_from_this());
}

QVector<shared_ptr<ACarte>> Joueur::selectionCartesChien(int taille){
    return strategieCourante.get()->selectionCartesChien(taille, shared_from_this());
}

void Joueur::selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie){
    strategieCourante.get()->selectionCarteAJouer(*pli,*partie, shared_from_this());
}

bool Joueur::isHumain(){
    return strategieCourante.get()->isHumain();
}

void Joueur::ajouterCarte(shared_ptr<ACarte> carte){
    strategieCourante.get()->ajouterCarte(carte, shared_from_this());
}

QString Joueur::getType() {
    return strategieCourante.get()->getType()
}

void Joueur::changerStrategieIA(){
    strategieCourante = ia;
}

void Joueur::changerStrategieHumain(){
    strategieCourante = humain;
}

void Joueur::addWidgetToAction(QWidget *q){
    action.get()->addWidget(q);
}

void Joueur::setSelectable(QVector<shared_ptr<ACarte>> s){
    selectable = s;
}

void Joueur::addWidgetToEmplacement(QWidget *q){
    emplacement.get()->addWidget(q);
}
