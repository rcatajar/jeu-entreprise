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
    tabdialog.cpp \
    tabproduction.cpp \
    tabfinance.cpp \
    widgetinput.cpp \
    turnwindow.cpp

HEADERS  += mainwindow.h \
    objet.h \
    entite.h \
    client.h \
    entreprise.h \
    moteurjeu.h \
    tabdialog.h \
    tabproduction.h \
    tabfinance.h \
    widgetinput.h \
    turnwindow.h

FORMS    += mainwindow.ui \
    tabdialog.ui \
    tabproduction.ui \
    tabfinance.ui \
    widgetinput.ui \
    turnwindow.ui

CONFIG += c++11
