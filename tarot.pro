QT += core
QT -= gui

TARGET = tarot
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    Joueur.cpp \
    Humain.cpp \
    ACarte.cpp \
    IValeur.cpp \
    ValeurSimple.cpp \
    ValeurValet.cpp \
    ValeurDame.cpp \
    ValeurCavalier.cpp \
    ValeurRoi.cpp \
    AForme.cpp \
    Pique.cpp \
    Coeur.cpp \
    Carreau.cpp \
    Trefle.cpp \
    Paquet.cpp \
    Atout.cpp \
    LePetit.cpp \
    Le21.cpp \
    Excuse.cpp

HEADERS += \
    Joueur.h \
    Humain.h \
    ACarte.h \
    IValeur.h \
    ValeurSimple.h \
    ValeurValet.h \
    ValeurDame.h \
    ValeurCavalier.h \
    ValeurRoi.h \
    AForme.h \
    Pique.h \
    Coeur.h \
    Carreau.h \
    Trefle.h \
    Paquet.h \
    Atout.h \
    LePetit.h \
    Le21.h \
    Excuse.h

