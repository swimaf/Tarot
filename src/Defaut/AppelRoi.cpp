#include "AppelRoi.h"

#include <QCoreApplication>
#include <iostream>
#include "CreationChien.h"
#include "../Carte/Trefle.h"
#include "../Carte/Coeur.h"
#include "../Carte/Pique.h"
#include "../Carte/Carreau.h"
#include "../Carte/Roi.h"

AppelRoi::AppelRoi(shared_ptr<Partie> partie) : Etat(partie)
{

}

void AppelRoi::demarrer() {
    cerr << "###################### APPEL AU ROI ##############" << endl;

    QVector<shared_ptr<ACarte>> rois;
    rois.push_back(make_shared<Carreau>(new Roi()));
    rois.push_back(make_shared<Coeur>(new Roi()));
    rois.push_back(make_shared<Pique>(new Roi()));
    rois.push_back(make_shared<Trefle>(new Roi()));

    shared_ptr<ACarte> roiAppele = partie->getPreneur()->appelerRoi(rois);
    partie->setRoiAppele(roiAppele);

    cerr << "Le roi qui a été appelé est le "+roiAppele->afficher() << endl;

    partie->setEtat(make_shared<CreationChien>(partie));

}
