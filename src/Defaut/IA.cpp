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


bool IA::choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Joueur> joueur){

    int index       = partie->get()->getNiveaux().indexOf(partie->get()->getEnchere());
    int nbAtout     = ACarte::compterNbAtout(joueur.get()->getJeux());
    int nbBout      = ACarte::compterNbBout(joueur.get()->getJeux());
    int nbValeurs   = ACarte::compterPoint(joueur.get()->getJeux());

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
    cerr << "Possède :" << endl;
    for(shared_ptr<ACarte> roi : rois) {
        cerr << roi->afficher() << endl;
    }

    for(int i=0; i<allRois.size(); ++i) {
        for(shared_ptr<ACarte> roi : rois) {
            if(allRois[i]->equals(roi)) {
                listRoi.remove(allRois[i]);
            }
        }
    }

    cerr << "Peux choisir :" << endl;

    for(shared_ptr<ACarte> roi : listRoi) {
        cerr << roi->afficher() << endl;
    }
    if(listRoi.size() == 0) {
        /** A REDEFINIR CHOISIR LA REINE SI IL A TOUT LES ROIS **/
        return rois[0];
    }
    auto carte = listRoi.begin();
    advance(carte, rand() % listRoi.size());
    return *carte;
}

QVector<shared_ptr<ACarte>> IA::selectionCartesChien(int taille, shared_ptr<Joueur> joueur){
    QVector<shared_ptr<ACarte>> chien;

    QVector<QVector<shared_ptr<ACarte>>> formes;
    formes.push_back(Filtre<Trefle, ACarte>::filtreClass(joueur.get()->getJeux(), false));
    formes.push_back(Filtre<Pique, ACarte>::filtreClass(joueur.get()->getJeux(), false));
    formes.push_back(Filtre<Coeur, ACarte>::filtreClass(joueur.get()->getJeux(), false));
    formes.push_back(Filtre<Carreau, ACarte>::filtreClass(joueur.get()->getJeux(), false));

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
        formes.push_back(Filtre<Trefle, ACarte>::filtreClass(joueur.get()->getJeux(), true));
        formes.push_back(Filtre<Pique, ACarte>::filtreClass(joueur.get()->getJeux(), true));
        formes.push_back(Filtre<Coeur, ACarte>::filtreClass(joueur.get()->getJeux(), true));
        formes.push_back(Filtre<Carreau, ACarte>::filtreClass(joueur.get()->getJeux(), true));
        formes.push_back(Filtre<Atout, ACarte>::filtreClass(joueur.get()->getJeux(), true));
        formes.push_back(Filtre<Excuse, ACarte>::filtreClass(joueur.get()->getJeux(), true));

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

void IA::ajouterCarte(shared_ptr<ACarte> carte, shared_ptr<Joueur> joueur){
    QPushButton *bouton = new QPushButton("");
    bouton->setStyleSheet("height:100%;"
                          "width:100%;"
                          "max-height: 100%;"
                          "max-width: 70%;"
                          "border-image :  url('../Tarot/img/cards/"+QString::fromStdString(carte->getURL())+".png');");
    joueur.get()->addWidgetToEmplacement(bouton);
    joueur.get()->getJeux().push_back(carte);
}

QString IA::getType() {
    return "IA";
}


void IA::trierJeux(shared_ptr<Joueur> joueur) {

}
