#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.h"
#include <QVector>
#include <memory>
#include "Chien.h"
#include "Paquet.h"
#include "Equipe.h"
#include "../Fenetre/FenetreJeux.h"

class Classement;
class Equipe;
class Etat;
class Partie : public enable_shared_from_this<Partie>
{
    public:
        Partie(shared_ptr<Paquet> paquet, QVector<shared_ptr<Joueur>> joueurs);
        QVector<shared_ptr<Joueur>> getJoueurs();
        shared_ptr<Chien> getChien();
        void setChien(shared_ptr<Chien> chien);
        shared_ptr<Paquet> getPaquet();
        void setEtat(shared_ptr<Etat> etat);
        void setPreneur(shared_ptr<Joueur> preneur);
        shared_ptr<Joueur> getPreneur();
        void setDonneur(shared_ptr<Joueur> donneur);
        shared_ptr<Joueur> getDonneur();
        void setRoiAppele(shared_ptr<ACarte> carte);
        shared_ptr<ACarte> getRoiAppele();
        void demarrer();
        void demarrerHumain(int);
        void transition();
        void choixEnchere(int);
        void continuer();

        void couperJoueur(int index);
        QVector<shared_ptr<Equipe>> getEquipes();
        void ajouterEquipe(shared_ptr<Equipe> equipe);
        void clearEquipes();
        shared_ptr<Classement> getClassement();
        shared_ptr<Niveau> getEnchere();
        void setEnchere(shared_ptr<Niveau> enchere);
        void compterPoint();
        shared_ptr<Equipe> getEquipeByJoueur(shared_ptr<Joueur> joueur);
        void reunirEquipe(shared_ptr<Joueur> deuxiemeMembre);
        shared_ptr<FenetreJeux> getFenetre();
        QVector<shared_ptr<Niveau>> getNiveaux();
        shared_ptr<ACarte> getCarteSelectionne();
        void setCarteSelectionne(shared_ptr<ACarte>);

        static shared_ptr<FenetreJeux> fenetre;



    private:
        shared_ptr<Paquet> paquet;
        shared_ptr<Chien> chien;
        shared_ptr<Niveau> enchere;
        shared_ptr<Etat> etat;
        shared_ptr<Joueur> preneur;
        shared_ptr<Joueur> donneur;
        shared_ptr<ACarte> roiAppele;
        QVector<shared_ptr<Equipe>> equipes;

        QVector<shared_ptr<Joueur>> joueurs;
        shared_ptr<Classement> classement;
        shared_ptr<FenetreJeux> jeux;
        QVector<shared_ptr<Niveau>> niveaux;
        shared_ptr<ACarte> carteSelectionne;


};

#endif // PARTIE_H
