#ifndef FENETREJEUX_H
#define FENETREJEUX_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include "Sleeper.h"
#include <memory>
#include "../Defaut/Joueur.h"

class FenetreJeux : public QMainWindow
{
    Q_OBJECT
public:
    explicit FenetreJeux(QWidget *parent = 0);
    void initEmplacement(int x, int y);
    void associerEmplacement(shared_ptr<Joueur> joueur, int indexJoueur, int taille);
    void createEnchere(shared_ptr<Joueur> joueur);
    void checkEnchere(int, bool);
    void setPartie(shared_ptr<Partie> partie);
    shared_ptr<Joueur> getHumain();
    void ajouterAction(QPushButton *button);
    void setVisibleContinuer(bool);
    void setVisibleValider(bool);

signals:

public slots:
    void pushButtonClicked();
    void enchereClicked();
    void onValider();
    void onContinuer();

private :
    QVector<shared_ptr<QBoxLayout>> placement;
    QGridLayout* centre;
    QVector<shared_ptr<QHBoxLayout>> emplacements;
    QHBoxLayout* enchere;
    QHBoxLayout* milieu;
    shared_ptr<QHBoxLayout> chien;
    QVector<QPushButton*> carteJoue;
    shared_ptr<Joueur> joueur;
    shared_ptr<Partie> partie;
    QPushButton *continuer;
    QPushButton *valider;
    int j;
};

#endif // JEUX_H
