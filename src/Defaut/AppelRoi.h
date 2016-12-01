#ifndef APPELROI_H
#define APPELROI_H

#include "Etat.h"

class AppelRoi : public Etat
{
    public:
        AppelRoi(shared_ptr<Partie> partie);
        void demarrer();
};

#endif // APPELROI_H
