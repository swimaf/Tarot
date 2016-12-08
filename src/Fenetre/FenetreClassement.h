#ifndef FENETRECLASSEMENT_H
#define FENETRECLASSEMENT_H

#include <QMainWindow>
#include <QTableWidget>
#include <memory>
#include "../Defaut/Joueur.h"


//Fenetre de classement permettant de visualiser les scores
class FenetreClassement : public QMainWindow
{
    Q_OBJECT
public:
    explicit FenetreClassement(QWidget *parent = 0);
    //On modifie le classement et on affiche la fenetre
    void updateAndShow(QVector<shared_ptr<Joueur>> joueurs);

signals:

public slots:
    void onQuitter();
    void onContinuer();

private:
    QTableWidget* tableWidget;
    QStringList tableHeader;
};

#endif // FENETRECLASSEMENT_H
