#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include <QVector>
#include <memory>
#include "Joueur.h"
#include <map>

class Classement
{
public:
    Classement(QVector<shared_ptr<Joueur>> joueurs);
    void ajouterPoints(shared_ptr<Joueur> joueurs, int points);
    QVector<shared_ptr<Joueur>> getClassement();
    static bool compare(shared_ptr<Joueur> a, shared_ptr<Joueur> b);


private :
    QVector<shared_ptr<Joueur>> joueurs;
};

#endif // CLASSEMENT_H
