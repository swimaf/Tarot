#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.h"
#include <vector>
#include <memory>
#include "Chien.h"
#include "Paquet.h"

class Etat;
class Partie : public enable_shared_from_this<Partie>
{
    public:
        Partie(shared_ptr<Paquet> paquet, vector<shared_ptr<Joueur>> joueurs);
        vector<shared_ptr<Joueur>> getJoueurs();
        shared_ptr<Chien> getChien();
        void setChien(shared_ptr<Chien> chien);
        shared_ptr<Paquet> getPaquet();
        void setEtat(shared_ptr<Etat> etat);
        void setPreneur(shared_ptr<Joueur> preneur);
        shared_ptr<Joueur> getPreneur();
        void setRoiAppele(shared_ptr<ACarte> carte);
        shared_ptr<ACarte> getRoiAppele();
        void demarrer();


    private:
        shared_ptr<Paquet> paquet;
        vector<shared_ptr<Joueur>> joueurs;
        shared_ptr<Chien> chien;
        shared_ptr<Etat> etat;
        shared_ptr<Joueur> preneur;
        shared_ptr<ACarte> roiAppele;

};

#endif // PARTIE_H
