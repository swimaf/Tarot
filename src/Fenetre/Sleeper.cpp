#include "Sleeper.h"
#include <iostream>
#include <QCoreApplication>

Sleeper::Sleeper()
{
}

void Sleeper::run() {
    sleep(1);
}

