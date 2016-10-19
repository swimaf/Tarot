#include "AppelRoi.h"

#include <QCoreApplication>
#include <iostream>
#include "CreationChien.h"
#include "Trefle.h"
#include "Coeur.h"
#include "Pique.h"
#include "Carreau.h"
#include "Roi.h"

AppelRoi::AppelRoi(shared_ptr<Partie> partie) : Etat(partie)
{

}

void AppelRoi::demarrer() {
    cerr << "###################### APPEL AU ROI ##############" << endl;

    vector<shared_ptr<ACarte>> rois;
    rois.push_back(make_shared<Carreau>("Roi", new Roi()));
    rois.push_back(make_shared<Coeur>("Roi", new Roi()));
    rois.push_back(make_shared<Pique>("Roi", new Roi()));
    rois.push_back(make_shared<Trefle>("Roi", new Roi()));

    shared_ptr<ACarte> roiAppele = partie->getPreneur()->appelerRoi(rois);
    partie->setRoiAppele(roiAppele);

    cerr << "Le roi qui a été appelé est le "+roiAppele->afficher() << endl;

    partie->setEtat(make_shared<CreationChien>(partie));

}
