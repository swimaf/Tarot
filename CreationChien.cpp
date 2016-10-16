#include "CreationChien.h"
#include <QCoreApplication>
#include <iostream>

CreationChien::CreationChien(shared_ptr<Partie> partie) : Etat(partie)
{

}

void CreationChien::demarrer() {
    cerr << "###################### CREATION DU CHIEN ##############" << endl;
    string test;
    cin >> test;
}
