#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class ACarte
{
    public:
        ACarte(string p_name);
        virtual double getValeur() = 0;
        virtual string afficher() const;
        string getName();
        virtual bool isBout() = 0;
        virtual bool isAtout() = 0;
        virtual bool isRoi();
        bool equals(shared_ptr<ACarte> a);
        virtual bool operator== (const ACarte* carte) const = 0;

        static int compterNbBout(vector<shared_ptr<ACarte>> cartes);
        static int compterNbAtout(vector<shared_ptr<ACarte>> cartes);
        static int compterPoint(vector<shared_ptr<ACarte>> cartes);
        static vector<shared_ptr<ACarte>> getRois(vector<shared_ptr<ACarte>> cartes);
        static void eraseElements(vector<shared_ptr<ACarte>> *cartes, vector<int> index);
        string name;


    protected:
};

#endif // CARTE_H
