#ifndef AFORME_H
#define AFORME_H

#include "ACarte.h"
#include "Tete.h"

class AForme : public ACarte
{

    public:
        AForme(Tete* tete);
        void setTete(Tete* tete);
        virtual string afficher() const;
        double getValeur();
        bool isBout();
        bool isAtout();
        bool isRoi();
        int poids() const;
        string getName() const;
        virtual string getType() const = 0;


    protected:
        Tete* tete;


};

#endif // AFORME_H
