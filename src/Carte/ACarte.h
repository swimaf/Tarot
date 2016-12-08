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
        // Fonction permettant de redéfinir l'opérateur ==, il doit être redéfini dans chaque sous classe
        virtual bool operator== (const ACarte* carte) const = 0;
        virtual string getName() const;
        virtual double getValeur() const;        
        virtual string getType() const;
        virtual int getPoids() const;
        // Redéfini dans la sous classe si nécessaire
        virtual bool isBout() const;
        // Redéfini dans la sous classe si nécessaire
        virtual bool isAtout() const;
        // Redéfini dans la sous classe si nécessaire
        virtual bool isRoi() const;
        // Redéfinition de equals
        bool equals(shared_ptr<ACarte> a);

        // Methode permettant de compter le nombre de bout dans un QVector de ACarte
        static int compterNbBout(QVector<shared_ptr<ACarte>> cartes);
        // Methode permettant de compter le nombre d'atouts dans un QVector de ACarte
        static int compterNbAtout(QVector<shared_ptr<ACarte>> cartes);
        // Methode permettant de compter le nombre de points total dans un QVector de ACarte
        static int compterPoint(QVector<shared_ptr<ACarte>> cartes);
        // Methode permettant de compter le nombre de rois dans un QVector de ACarte
        static QVector<shared_ptr<ACarte>> getRois(QVector<shared_ptr<ACarte>> cartes);
        // Methode permettant de supprimer des cartes selon les indices donner dans le QVector d'entiers
        static void eraseElements(QVector<shared_ptr<ACarte>> *cartes, QVector<int> index);
        // Filtres
        static QVector<shared_ptr<ACarte>> filtre(string, QVector<shared_ptr<ACarte>>);
        static QVector<shared_ptr<ACarte>> filtreByValue(double, QVector<shared_ptr<ACarte>>);

    protected:
        double valeur; // point
        int poids; // poids pour pouvoir comparer avec une autre carte qui est la plus forte
        string type; // Trefle, Carreau, Coeur, Pique, Atout ..
        string name; // 1, 2, 3 ... Dame, Roi
};

#endif // CARTE_H
