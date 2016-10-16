#include "AppelRoi.h"

#include <QCoreApplication>
#include <iostream>
#include "CreationChien.h"

AppelRoi::AppelRoi(shared_ptr<Partie> partie) : Etat(partie)
{

}

void AppelRoi::demarrer() {
    cerr << "###################### APPEL AU ROI ##############" << endl;
    shared_ptr<ACarte> roiAppele = partie->getPreneur()->appelerRoi();
    partie->setRoiAppele(roiAppele);

    cerr << "Le roi qui a été appelé est le "+roiAppele->afficher() << endl;

    partie->setEtat(make_shared<CreationChien>(partie));

}
