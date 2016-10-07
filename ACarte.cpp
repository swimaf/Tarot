#include "ACarte.h"
#include "Coeur.h"
#include "ValeurValet.h"
#include "ValeurCavalier.h"
#include "ValeurDame.h"
#include "ValeurRoi.h"

using namespace std;

ACarte::ACarte(std::string p_name)
{
    name = p_name;
}


string ACarte::afficher() {
    return name;
}

string ACarte::getName() {
    return name;
}

