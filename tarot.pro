QT += core
QT -= gui

TARGET = bin/tarot
CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14


SOURCES += src/main.cpp \
    src/Joueur.cpp \
    src/Humain.cpp \
    src/ACarte.cpp \
    src/AForme.cpp \
    src/Pique.cpp \
    src/Coeur.cpp \
    src/Carreau.cpp \
    src/Trefle.cpp \
    src/Paquet.cpp \
    src/Atout.cpp \
    src/LePetit.cpp \
    src/Le21.cpp \
    src/Excuse.cpp \
    src/Equipe.cpp \
    src/Chien.cpp \
    src/Etat.cpp \
    src/Partie.cpp \
    src/Distribuer.cpp \
    src/Enchere.cpp \
    src/Niveau.cpp \
    src/Garde.cpp \
    src/IA.cpp \
    src/Constantes.cpp \
    src/Prise.cpp \
    src/Passer.cpp \
    src/AppelRoi.cpp \
    src/CreationChien.cpp \
    src/JouerLeJeux.cpp \
    src/Cavalier.cpp \
    src/Dame.cpp \
    src/Roi.cpp \
    src/Simple.cpp \
    src/Valet.cpp \
    src/Tete.cpp \
    src/Filtre.cpp \
    src/Pli.cpp \
    src/Classement.cpp

HEADERS += \
    src/Joueur.h \
    src/Humain.h \
    src/ACarte.h \
    src/AForme.h \
    src/Pique.h \
    src/Coeur.h \
    src/Carreau.h \
    src/Trefle.h \
    src/Paquet.h \
    src/Atout.h \
    src/LePetit.h \
    src/Le21.h \
    src/Excuse.h \
    src/Equipe.h \
    src/Chien.h \
    src/Etat.h \
    src/Partie.h \
    src/Distribuer.h \
    src/Enchere.h \
    src/Niveau.h \
    src/Garde.h \
    src/IA.h \
    src/Constantes.h \
    src/Prise.h \
    src/Passer.h \
    src/AppelRoi.h \
    src/CreationChien.h \
    src/JouerLeJeux.h \
    src/Valet.h \
    src/Tete.h \
    src/Cavalier.h \
    src/Simple.h \
    src/Dame.h \
    src/Roi.h \
    src/Filtre.h \
    src/Pli.h \
    src/Classement.h

