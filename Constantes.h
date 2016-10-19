#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <vector>
#include <memory>
#include <ACarte.h>

class Constantes
{
    public:
    const static int NB_CARTES = 78;
    const static int COEFF_BOUT = 10;
    const static int COEFF_ATOUT = 3;
    const static int COEFF_VALEUR = 1;

    static bool compare(vector<shared_ptr<ACarte>> i, vector<shared_ptr<ACarte>> j) {
        return (i.size()<j.size());
    }
};

#endif // CONSTANTES_H
