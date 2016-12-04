#ifndef FENETRECLASSEMENT_H
#define FENETRECLASSEMENT_H

#include <QMainWindow>
#include <QTableWidget>
#include <memory>
#include "../Defaut/Joueur.h"

class FenetreClassement : public QMainWindow
{
    Q_OBJECT
public:
    explicit FenetreClassement(QWidget *parent = 0);
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
