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


SOURCES += tests_objet.cpp

# On inclut les classes du projet principale a tester
SOURCES += ../jeu-entreprise/objet.cpp \
    ../jeu-entreprise/entite.cpp \
    ../jeu-entreprise/client.cpp \
    ../jeu-entreprise/entreprise.cpp \
    ../jeu-entreprise/moteurjeu.cpp

HEADERS  += ../jeu-entreprise/objet.h \
    ../jeu-entreprise/entite.h \
    ../jeu-entreprise/client.h \
    ../jeu-entreprise/entreprise.h \
    ../jeu-entreprise/moteurjeu.h


DEFINES += SRCDIR=\\\"$$PWD/\\\"

CONFIG += c++11

