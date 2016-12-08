#ifndef ETAT_H
#define ETAT_H

#include "Partie.h"
#include <memory>

//Pattern Etat
class Etat
{
    public:
        //On passe le context en parametre
        Etat(shared_ptr<Partie> partie);
        virtual void demarrer() = 0;
        //Fonction lors d'un clic sur une carte
        virtual void demarrerHumain(int indexCarte);
        //Passer au prochain état
        virtual void transition() {}
        //Si on clic sur le bonton continuer
        virtual void continuer() {}
        //Fonction pour les boutons enchères
        virtual void choixEnchere(int indexCarte);

    protected:
        shared_ptr<Partie> partie;

};

#endif // ETAT_H
