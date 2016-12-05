#ifndef FENETREJEUX_H
#define FENETREJEUX_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include "Sleeper.h"
#include <memory>
#include <QLabel>
#include "../Defaut/Joueur.h"

class FenetreJeux : public QMainWindow
{
    Q_OBJECT
public:
    explicit FenetreJeux(QWidget *parent = 0);
    void initialisation(shared_ptr<Partie> partie);
    void initEmplacement(int x, int y);
    void associerEmplacement(shared_ptr<Joueur> joueur, int indexJoueur, int taille);
    void createEnchere(shared_ptr<Joueur> joueur);
    void checkEnchere(int, bool);
    shared_ptr<Joueur> getHumain();
    void ajouterAction(QPushButton *button);
    void ajouterActionRoi(QPushButton *button);
    void setVisibleContinuer(bool);
    void setVisibleValider(bool);
    void setText(string text="");
    void showRoi(shared_ptr<ACarte> roi);
    void eraseRoi();
    void eraseRois();

signals:

public slots:
    void pushButtonClicked();
    void enchereClicked();
    void onValider();
    void onContinuer();
    void onClickRoi();


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
    QLabel* label;
    QGridLayout *gridLayout;
    int j;
};

#endif // JEUX_H
