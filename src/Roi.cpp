#include "Roi.h"

Roi::Roi()
{

}

double Roi::getValeur() {
    return 4.5;
}

bool Roi::isRoi() {
    return true;
}


int Roi::getPoids() const {
    return 14;
}

string Roi::getName() const {
    return "Roi";
}
