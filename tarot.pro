QT += core
QT -= gui

TARGET = tarot
CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle
LIBS += \
       -lboost_system\


TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14


SOURCES += main.cpp \
    Joueur.cpp \
    Humain.cpp \
    ACarte.cpp \
    AForme.cpp \
    Pique.cpp \
    Coeur.cpp \
    Carreau.cpp \
    Trefle.cpp \
    Paquet.cpp \
    Atout.cpp \
    LePetit.cpp \
    Le21.cpp \
    Excuse.cpp \
    Equipe.cpp \
    Chien.cpp \
    Etat.cpp \
    Partie.cpp \
    Distribuer.cpp \
    Enchere.cpp \
    Niveau.cpp \
    Garde.cpp \
    IA.cpp \
    Constantes.cpp \
    Prise.cpp \
    Passer.cpp \
    AppelRoi.cpp \
    CreationChien.cpp \
    JouerLeJeux.cpp \
    Cavalier.cpp \
    Dame.cpp \
    Roi.cpp \
    Simple.cpp \
    Valet.cpp \
    Tete.cpp \
    Filtre.cpp

HEADERS += \
    Joueur.h \
    Humain.h \
    ACarte.h \
    AForme.h \
    Pique.h \
    Coeur.h \
    Carreau.h \
    Trefle.h \
    Paquet.h \
    Atout.h \
    LePetit.h \
    Le21.h \
    Excuse.h \
    Equipe.h \
    Chien.h \
    Etat.h \
    Partie.h \
    Distribuer.h \
    Enchere.h \
    Niveau.h \
    Garde.h \
    IA.h \
    Constantes.h \
    Prise.h \
    Passer.h \
    AppelRoi.h \
    CreationChien.h \
    JouerLeJeux.h \
    Valet.h \
    Tete.h \
    Cavalier.h \
    Simple.h \
    Dame.h \
    Roi.h \
    Filtre.h

