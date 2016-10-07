#ifndef AFORME_H
#define AFORME_H

#include "ACarte.h"
#include "IValeur.h"

class AForme : public ACarte
{

    public:
        AForme(std::string p_name);
        AForme(std::string p_name, IValeur* iValeur);
        void setIValeur(IValeur* iValeur);
        virtual std::string afficher();
        double getValeur();

    protected:
        IValeur* iValeur;

};

#endif // AFORME_H
