#ifndef AFORME_H
#define AFORME_H

#include "ACarte.h"
#include "Tete.h"

class AForme : public ACarte
{

    public:
        AForme(string p_name);
        AForme(string p_name, Tete* tete);
        void setTete(Tete* tete);
        virtual string afficher() const;
        double getValeur();
        bool isBout();
        bool isAtout();
        bool isRoi();

    protected:
        Tete* tete;

};

#endif // AFORME_H
