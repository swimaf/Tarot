#ifndef NIVEAU_H
#define NIVEAU_H

#include <memory>

using namespace std;
//Niveau permet de definir l'ensemble des niveau
class Niveau
{
    public:
        Niveau();
        virtual shared_ptr<Niveau> getSuivant() = 0;
        virtual string getNom() = 0;
        virtual int seuil() = 0;
        virtual int multiplicateur() = 0;

};

#endif // NIVEAU_H
