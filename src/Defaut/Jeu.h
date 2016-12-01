#ifndef JEU_H
#define JEU_H

#include <QObject>
#include "Joueur.h"
#include "IA.h"
#include "Humain.h"
#include <memory>


class QTimer;
class Jeu : public QObject
{
    Q_OBJECT

    public:
        Jeu();
        QVector<shared_ptr<Joueur>> creerJoueur();
        void exec();
        virtual ~Jeu() {};


    public slots:
        void lancer();


    private :
         shared_ptr<Partie> partie;
         QTimer *timer;
};

#endif // JEU_H
