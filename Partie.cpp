#include "Partie.h"
#include "Distribuer.h"

Partie::Partie()
{
    etat = new Distribuer(*this);
}

Chien Partie::getChien() {
    return *chien;
}
