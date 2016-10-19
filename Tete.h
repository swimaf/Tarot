#ifndef IVALEUR_H
#define IVALEUR_H


class Tete
{
    public:
        Tete();
        virtual double getValeur() = 0;
        virtual bool isRoi();
};

#endif
