#include "IA.h"
#include "Partie.h"
#include "Filtre.h"
#include "../Carte/Trefle.h"
#include "../Carte/Carreau.h"
#include "../Carte/Coeur.h"
#include "../Carte/Pique.h"
#include "../Carte/Atout.h"
#include "../Carte/Excuse.h"
#include "Constantes.h"

IA::IA() : StrategieJeu()
{

}


bool IA::choixEnchere(shared_ptr<Partie> *partie, QVector<shared_ptr<ACarte>> jeux){

    int index       = partie->get()->getNiveaux().indexOf(partie->get()->getEnchere());
    int nbAtout     = ACarte::compterNbAtout(jeux);
    int nbBout      = ACarte::compterNbBout(jeux);
    int nbValeurs   = ACarte::compterPoint(jeux);

    int nbJoueurs = partie->get()->getJoueurs().size();
    int coeff = nbAtout * Constantes::COEFF_ATOUT + nbBout * Constantes::COEFF_BOUT + nbValeurs*Constantes::COEFF_VALEUR + nbJoueurs*10;

    bool choix= false;

    for(int i=partie->get()->getNiveaux().size() - 1; i> index ; i--) {
       if(coeff > partie->get()->getNiveaux()[i]->seuil()) {
           partie->get()->setEnchere(partie->get()->getNiveaux()[i]);
           choix = true;
       }
    }

    return choix;
}

shared_ptr<ACarte> IA::appelerRoi(QVector<shared_ptr<ACarte>> allRois, shared_ptr<Joueur> joueur){

    list<shared_ptr<ACarte>> listRoi;
    copy(allRois.begin(), allRois.end(), back_inserter(listRoi));

    QVector<shared_ptr<ACarte>> rois = ACarte::getRois(joueur.get()->getJeux());

    for(int i=0; i<allRois.size(); ++i) {
        for(shared_ptr<ACarte> roi : rois) {
            if(allRois[i]->equals(roi)) {
                listRoi.remove(allRois[i]);
            }
        }
    }

    if(listRoi.size() == 0) {
        /** A REDEFINIR CHOISIR LA REINE SI IL A TOUT LES ROIS **/
        return rois[0];
    }
    auto carte = listRoi.begin();
    advance(carte, rand() % listRoi.size());
    return *carte;
}

QVector<shared_ptr<ACarte>> IA::selectionCartesChien(int taille, QVector<shared_ptr<ACarte>> jeux){
    QVector<shared_ptr<ACarte>> chien;

    QVector<QVector<shared_ptr<ACarte>>> formes;
    formes.push_back(Filtre::execute(jeux, false, "Trefle"));
    formes.push_back(Filtre::execute(jeux, false, "Coeur"));
    formes.push_back(Filtre::execute(jeux, false, "Carreau"));
    formes.push_back(Filtre::execute(jeux, false, "Pique"));

    sort(formes.begin(), formes.end(), Constantes::compare);

    unsigned int i =0, k =-1;
    while(chien.size() != taille) {
        if(k < formes[i].size()) {
            chien.push_back(formes[i][k]);
            k++;
        } else {
            i++;
            k = 0;
        }
    }

    return chien;
}

void IA::selectionCarteAJouer(Pli *pli, shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur){
    if(pli->getCartes().isEmpty()) {
        QVector<QVector<shared_ptr<ACarte>>> formes;
        formes.push_back(Filtre::execute(joueur->getJeux(), true, "Trefle"));
        formes.push_back(Filtre::execute(joueur->getJeux(), true, "Coeur"));
        formes.push_back(Filtre::execute(joueur->getJeux(), true, "Carreau"));
        formes.push_back(Filtre::execute(joueur->getJeux(), true, "Pique"));
        formes.push_back(Filtre::execute(joueur->getJeux(), true, "Atout"));
        formes.push_back(Filtre::execute(joueur->getJeux(), true, "Excuse"));


        for(QVector<shared_ptr<ACarte>> f:formes) {
            if(!f.isEmpty()) {
                partie->get()->setCarteSelectionne(f[0]); // A REDEFINIR
                joueur.get()->jouerCarte(f[0]);
                break;
            }
        }
    } else {
        QVector<shared_ptr<ACarte>> cartes = joueur.get()->getCartesJouable(pli);
        partie->get()->setCarteSelectionne(cartes[0]);
        joueur.get()->jouerCarte(cartes[0]);
    }
}

bool IA::isHumain(){
    return false;
}

QPushButton* IA::ajouterCarte(shared_ptr<ACarte> carte){

    QPushButton *bouton = new QPushButton("");
    bouton->setStyleSheet("height:100%;"
                          "width:100%;"
                          "max-height: 100%;"
                          "max-width: 70%;"
                          "border-image :  url('../Tarot/img/cards/"+QString::fromStdString(carte->getURL())+".png');");
    return bouton;
}

QString IA::getType() {
    return "IA";
}

void IA::trierJeux(shared_ptr<Joueur> joueur) {}
