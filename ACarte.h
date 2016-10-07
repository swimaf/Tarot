#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class ACarte
{
    public:
        ACarte(string p_name);
        virtual double getValeur() = 0;
        virtual string afficher();
        string getName();

    protected:
      string name;
};

#endif // CARTE_H
