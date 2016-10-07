#include "Humain.h"

Humain::Humain(std::string n) : Joueur(n)
{
}

std::string Humain::toString() {
    return "Je suis un humain et je m'appelle "+Joueur::name;
}
