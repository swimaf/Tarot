#include "Simple.h"

Simple::Simple(int val) : val(val)
{

}

double Simple::getValeur() {
    return 0.5;
}



int Simple::getPoids() const {
    return val;
}

string Simple::getName() const {
    return to_string(val);
}
