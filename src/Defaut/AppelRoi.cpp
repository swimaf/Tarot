#include "AppelRoi.h"

#include "CreationChien.h"
#include "../Carte/Trefle.h"
#include "../Carte/Coeur.h"
#include "../Carte/Pique.h"
#include "../Carte/Carreau.h"
#include "../Carte/Roi.h"

AppelRoi::AppelRoi(shared_ptr<Partie> partie) : Etat(partie)
{
    isAppele = false;
    rois.push_back(make_shared<Roi>(make_shared<Carreau>()));
    rois.push_back(make_shared<Roi>(make_shared<Coeur>()));
    rois.push_back(make_shared<Roi>(make_shared<Pique>()));
    rois.push_back(make_shared<Roi>(make_shared<Trefle>()));
}

void AppelRoi::demarrer() {
    isAppele = true;

    if(partie->getPreneur()->isHumain()) {
        partie->getPreneur()->appelerRoi(rois);
    } else {
        shared_ptr<ACarte> roiAppele = partie->getPreneur()->appelerRoi(rois);
        partie->setRoiAppele(roiAppele);
        partie->getFenetre()->setText("Le roi appelé :");
        partie->getFenetre()->showRoi(roiAppele);
        partie->getFenetre()->setVisibleContinuer(true);
    }
}

void AppelRoi::demarrerHumain(int indexCarte) {
    partie->setRoiAppele(rois[indexCarte]);
    partie->getFenetre()->setText("Le roi appelé :");
    partie->getFenetre()->showRoi(rois[indexCarte]);
    partie->getFenetre()->setVisibleContinuer(true);
    partie->getFenetre()->eraseRois();
}

void AppelRoi::transition() {
    if(isAppele) {
        partie->setEtat(make_shared<CreationChien>(partie));
        partie->demarrer();
    } else {
        demarrer();
    }
}

void AppelRoi::continuer() {
    partie->getFenetre()->eraseRoi();
    transition();
}
