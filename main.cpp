#include <QCoreApplication>
#include "Joueur.h"
#include "Humain.h"
#include "ACarte.h"
#include <iostream>
#include <vector>
#include <memory>
#include <Paquet.h>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Joueur joueur("Etienne");
    Humain humain("Pierre");

    cerr << joueur.toString() <<endl;
    cerr << humain.toString() <<endl << endl;

    Paquet& paquet = Paquet::getInstance();
    paquet.melanger();
    for(auto &carte : paquet.getCartes()) {
        cerr << carte->afficher() << " , valeur : " << carte->getValeur() <<endl;
    }
    cerr << paquet.getCartes().size() <<endl;



    return a.exec();
}

