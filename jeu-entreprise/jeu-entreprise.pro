#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T17:05:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jeu-entreprise
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objet.cpp \
    entite.cpp \
    client.cpp \
    entreprise.cpp \
    moteurjeu.cpp \
    turnwindow.cpp \
    tabwidget.cpp \
    inputwidget.cpp \
    loadingwindow.cpp \
    graphsfinance.cpp \
    graphsproduction.cpp \
    graphsrecherche.cpp \
    graphsmarketing.cpp \
    historique.cpp

HEADERS  += mainwindow.h \
    objet.h \
    entite.h \
    client.h \
    entreprise.h \
    moteurjeu.h \
    turnwindow.h \
    tabwidget.h \
    inputwidget.h \
    loadingwindow.h \
    graphsfinance.h \
    graphsproduction.h \
    graphsrecherche.h \
    graphsmarketing.h \
    historique.h

FORMS    += mainwindow.ui \
    turnwindow.ui \
    tabwidget.ui \
    inputwidget.ui \
    loadingwindow.ui \
    graphsfinance.ui \
    graphsproduction.ui \
    graphsrecherche.ui \
    graphsmarketing.ui

CONFIG += c++11
