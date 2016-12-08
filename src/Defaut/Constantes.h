#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <QVector>
#include <memory>
#include "../Carte/ACarte.h"


class Constantes
{
    public:
    const static int NB_CARTES = 78;
    const static int COEFF_BOUT = 10;
    const static int COEFF_ATOUT = 3;
    const static int COEFF_VALEUR = 1;

    static bool compare(QVector<shared_ptr<ACarte>> i, QVector<shared_ptr<ACarte>> j) {
        return (i.size() < j.size());
    }

    static bool sortJeux(shared_ptr<ACarte> a, shared_ptr<ACarte> b) {
        return a->getPoids() < b->getPoids();
    }


    static long mod(long a, long b){ return (a%b+b)%b; } // Redefinition
};

#endif // CONSTANTES_H
