#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <QVector>
#include <memory>

using namespace std;

class ACarte
{
    public:
        ACarte();
        virtual double getValeur() = 0;
        virtual string afficher() const;
        virtual string getName() const = 0;
        virtual bool isBout() = 0;
        virtual bool isAtout() = 0;
        virtual bool isRoi();
        virtual string getType() const = 0;
        virtual int poids() const = 0;
        bool equals(shared_ptr<ACarte> a);
        virtual bool operator== (const ACarte* carte) const = 0;

        static int compterNbBout(QVector<shared_ptr<ACarte>> cartes);
        static int compterNbAtout(QVector<shared_ptr<ACarte>> cartes);
        static int compterPoint(QVector<shared_ptr<ACarte>> cartes);
        static QVector<shared_ptr<ACarte>> getRois(QVector<shared_ptr<ACarte>> cartes);
        static void eraseElements(QVector<shared_ptr<ACarte>> *cartes, QVector<int> index);
        static QVector<shared_ptr<ACarte>> filtre(string, QVector<shared_ptr<ACarte>>);
        static QVector<shared_ptr<ACarte>> filtreByValue(double, QVector<shared_ptr<ACarte>>);
};

#endif // CARTE_H
