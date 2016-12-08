#include "AForme.h"

AForme::AForme(double valeur, string type, int poids) : ACarte(valeur,poids,type,"")
{

}

string AForme::getURL() const {
    return type;
}
