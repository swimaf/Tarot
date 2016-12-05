#include <iostream>
#include <QVector>

#include <QApplication>
#include <thread>
#include <stdio.h>
#include "Defaut/Jeu.h"

using namespace std;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Jeu jeu;
    jeu.exec();

    return a.exec();
}

