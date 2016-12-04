#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include <QVector>
#include <memory>
#include "Joueur.h"
#include <map>
#include "../Fenetre/FenetreClassement.h"

class Classement
{
public:
    Classement(QVector<shared_ptr<Joueur>> joueurs);
    void ajouterPoints(shared_ptr<Joueur> joueurs, int points);
    QVector<shared_ptr<Joueur>> getClassement();
    void show();
    static bool compare(shared_ptr<Joueur> a, shared_ptr<Joueur> b);


private :
    QVector<shared_ptr<Joueur>> joueurs;
    shared_ptr<FenetreClassement> fenetre;
};

#endif // CLASSEMENT_H
