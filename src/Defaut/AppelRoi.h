#ifndef APPELROI_H
#define APPELROI_H

#include "Etat.h"

class AppelRoi : public Etat
{
    public:
        AppelRoi(shared_ptr<Partie> partie);
        void demarrer();
        void demarrerHumain(int indexCarte);
        void transition();
        void continuer();

    private:
        bool isAppele;
         QVector<shared_ptr<ACarte>> rois;
};

#endif // APPELROI_H
