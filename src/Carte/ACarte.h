#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <QVector>
#include <memory>

using namespace std;

// Classe abstraite
class ACarte
{
    public:
        ACarte(double valeur, int poids, string type, string name);
        // Retourne l'URL de l'image la carte
        virtual string getURL() const = 0;
        virtual bool operator== (const ACarte* carte) const = 0;
        virtual string getName() const;
        virtual double getValeur() const;
        virtual string getType() const;
        virtual int getPoids() const;
        virtual bool isBout() const;
        virtual bool isAtout() const;
        virtual bool isRoi() const;
        bool equals(shared_ptr<ACarte> a);

        static int compterNbBout(QVector<shared_ptr<ACarte>> cartes);
        static int compterNbAtout(QVector<shared_ptr<ACarte>> cartes);
        static int compterPoint(QVector<shared_ptr<ACarte>> cartes);
        static QVector<shared_ptr<ACarte>> getRois(QVector<shared_ptr<ACarte>> cartes);
        static void eraseElements(QVector<shared_ptr<ACarte>> *cartes, QVector<int> index);
        static QVector<shared_ptr<ACarte>> filtre(string, QVector<shared_ptr<ACarte>>);
        static QVector<shared_ptr<ACarte>> filtreByValue(double, QVector<shared_ptr<ACarte>>);

    protected:
        double valeur;
        int poids;
        string type;
        string name;
};

#endif // CARTE_H
