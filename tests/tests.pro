#-------------------------------------------------
#
# Project created by QtCreator 2015-11-28T13:03:52
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# Testrunner
SOURCES += main.cpp

# Les classes de tests
SOURCES += tests_objet.cpp
HEADERS += tests_objet.h

SOURCES += tests_entite.cpp
HEADERS += tests_entite.h

SOURCES += tests_client.cpp
HEADERS += tests_client.h

SOURCES += tests_entreprise.cpp
HEADERS += tests_entreprise.h


# On inclut les classes du projet principale a tester
SOURCES += ../jeu-entreprise/objet.cpp \
    ../jeu-entreprise/entite.cpp \
    ../jeu-entreprise/client.cpp \
    ../jeu-entreprise/entreprise.cpp \
    ../jeu-entreprise/moteurjeu.cpp \
    ../jeu-entreprise/historique.cpp


HEADERS  += ../jeu-entreprise/objet.h \
    ../jeu-entreprise/entite.h \
    ../jeu-entreprise/client.h \
    ../jeu-entreprise/entreprise.h \
    ../jeu-entreprise/moteurjeu.h \
    ../jeu-entreprise/historique.h

CONFIG += c++11

