#include "Humain.h"
#include <QCoreApplication>
#include <iostream>
#include <Passer.h>
#include "AForme.h"
#include "Trefle.h"
#include "Coeur.h"
#include "Pique.h"
#include "Carreau.h"
#include "ValeurRoi.h"


Humain::Humain(std::string n) : Joueur(n)
{
}

string Humain::toString() {
    return "Je suis un humain et je m'appelle "+Joueur::name;
}

bool Humain::choixEnchere(shared_ptr<Partie> partie, shared_ptr<Niveau> *niveau) {

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


shared_ptr<ACarte> Humain::appelerRoi() {
    vector<shared_ptr<ACarte>> rois;
    rois.push_back(make_shared<Carreau>("Roi", new ValeurRoi()));
    rois.push_back(make_shared<Coeur>("Roi", new ValeurRoi()));
    rois.push_back(make_shared<Pique>("Roi", new ValeurRoi()));
    rois.push_back(make_shared<Trefle>("Roi", new ValeurRoi()));

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

