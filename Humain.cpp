#include "Humain.h"
#include <QCoreApplication>
#include <iostream>
#include <Passer.h>
#include "AForme.h"
#include <algorithm>


Humain::Humain(std::string n) : Joueur(n)
{
}

string Humain::toString() {
    return "Je suis un humain et je m'appelle "+Joueur::name;
}

bool Humain::choixEnchere(shared_ptr<Partie> *partie, shared_ptr<Niveau> *niveau) {


    cerr << "Votre choix : "+name << endl;
    vector<shared_ptr<Niveau>> vNiveau;
    vNiveau.push_back(make_shared<Passer>());


    /***
     *
     *
     *
     *
    */
    cerr << "Vos cartes : " << endl;
    for(shared_ptr<ACarte> carte:jeux) {
        cerr << carte->afficher() << ", ";
    }


    /***
     *
     *
     *
     *
     * */
    cerr << "0) " << vNiveau[0]->getNom() << endl;

    vNiveau.push_back(niveau->get()->getSuivant());
    int i= 1;
    while(vNiveau[i] != NULL) {
        cerr << i << ") " << vNiveau[i]->getNom() << endl;
        vNiveau.push_back(vNiveau[i]->getSuivant());
        i++;
    }
    string stringUtilisateur;
    cin >> stringUtilisateur;
    int choixUtilisateur = stoi(stringUtilisateur);
    if(choixUtilisateur > 0) {
        niveau->operator =(vNiveau[choixUtilisateur]);
        cerr << "Vous avec choisie : " << niveau->get()->getNom() << endl;
    }
    return choixUtilisateur > 0;
}


shared_ptr<ACarte> Humain::appelerRoi(vector<shared_ptr<ACarte>> rois) {

    cerr << "Choisir votre roi :" << endl;
    int i=0;
    for(shared_ptr<ACarte> roi : rois) {
        cerr << i<< ") "<< roi->afficher() << endl;
        i++;
    }
    string stream;
    cin >> stream;
    shared_ptr<ACarte> roiAppele = rois[stoi(stream)];
    cerr << "Vous avez choisie le :" + roiAppele->afficher() << endl;

    return roiAppele;
}

vector<shared_ptr<ACarte>> Humain::selectionCartesChien(int taille) {
    vector<int> element;
    unsigned int i=0;
    cerr << "Choisir les cartes que vous voulez :" << endl;
    for(shared_ptr<ACarte> carte:jeux) {
        cerr << "  "<<i << ") "+carte->afficher() << endl;
        i++;
    }
    string stream;
    unsigned int index;
    i = 1;
    while(element.size() != taille) {
        cerr << i << " cartes :" << endl;
        cin >> stream;
        index = stoi(stream);
        if(index < jeux.size() && find(element.begin(), element.end(), index) == element.end()) {
            element.push_back(index);
            i++;
        } else {
            cerr << "Cette carte à déjà été choisie :" << endl;
        }
    }
    vector<shared_ptr<ACarte>> cartes;
    for(int i = 0; i<taille; i++) {
        cartes.push_back(jeux[element[i]]);
    }
    for(int i = 0; i<taille; i++) {
        jeux.erase(jeux.begin()+ element[i]);
    }
    return cartes;
}


shared_ptr<ACarte> Humain::selectionCarteAJouer() {

    int i = 0;
    for(shared_ptr<ACarte> carte : jeux) {
        cerr << i << ") "<<carte->afficher() << endl;
        i++;
    }
    string t; /**A MODIFIER**/
    cin >> t;

    return jeux[stoi(t)];
}

