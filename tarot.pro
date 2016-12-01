QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bin/tarot
CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14


SOURCES += src/main.cpp \
    src/Carte/ACarte.cpp \
    src/Fenetre/Sleeper.cpp \
    src/Carte/AForme.cpp \
    src/Carte/Atout.cpp \
    src/Carte/Carreau.cpp \
    src/Carte/Cavalier.cpp \
    src/Carte/Coeur.cpp \
    src/Carte/Dame.cpp \
    src/Carte/Excuse.cpp \
    src/Carte/Le21.cpp \
    src/Carte/LePetit.cpp \
    src/Carte/Pique.cpp \
    src/Carte/Roi.cpp \
    src/Carte/Simple.cpp \
    src/Carte/Tete.cpp \
    src/Carte/Trefle.cpp \
    src/Defaut/AppelRoi.cpp \
    src/Defaut/Chien.cpp \
    src/Defaut/Classement.cpp \
    src/Defaut/Constantes.cpp \
    src/Defaut/CreationChien.cpp \
    src/Defaut/Distribuer.cpp \
    src/Defaut/Enchere.cpp \
    src/Defaut/Equipe.cpp \
    src/Defaut/Etat.cpp \
    src/Defaut/Filtre.cpp \
    src/Defaut/Garde.cpp \
    src/Defaut/Humain.cpp \
    src/Defaut/IA.cpp \
    src/Defaut/JouerLeJeux.cpp \
    src/Defaut/Joueur.cpp \
    src/Defaut/Niveau.cpp \
    src/Defaut/Paquet.cpp \
    src/Defaut/Partie.cpp \
    src/Defaut/Passer.cpp \
    src/Defaut/Pli.cpp \
    src/Defaut/Prise.cpp \
    src/Carte/Valet.cpp \
    src/Fenetre/FenetreJeux.cpp \
    src/Defaut/Jeu.cpp

HEADERS += \
    src/Fenetre/Sleeper.h \
    src/Carte/ACarte.h \
    src/Carte/AForme.h \
    src/Carte/Atout.h \
    src/Carte/Carreau.h \
    src/Carte/Cavalier.h \
    src/Carte/Coeur.h \
    src/Carte/Dame.h \
    src/Carte/Excuse.h \
    src/Carte/Le21.h \
    src/Carte/LePetit.h \
    src/Carte/Pique.h \
    src/Carte/Roi.h \
    src/Carte/Simple.h \
    src/Carte/Tete.h \
    src/Carte/Trefle.h \
    src/Defaut/AppelRoi.h \
    src/Defaut/Chien.h \
    src/Defaut/Classement.h \
    src/Defaut/Constantes.h \
    src/Defaut/CreationChien.h \
    src/Defaut/Distribuer.h \
    src/Defaut/Enchere.h \
    src/Defaut/Equipe.h \
    src/Defaut/Etat.h \
    src/Defaut/Filtre.h \
    src/Defaut/Garde.h \
    src/Defaut/Humain.h \
    src/Defaut/IA.h \
    src/Defaut/JouerLeJeux.h \
    src/Defaut/Joueur.h \
    src/Defaut/Niveau.h \
    src/Defaut/Paquet.h \
    src/Defaut/Partie.h \
    src/Defaut/Passer.h \
    src/Defaut/Petite.h \
    src/Defaut/Pli.h \
    src/Defaut/Prise.h \
    src/Carte/Valet.h \
    src/Fenetre/FenetreJeux.h \
    src/Defaut/Jeu.h

