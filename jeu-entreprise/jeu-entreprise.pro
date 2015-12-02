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
    generaltab.cpp \
    permissionstab.cpp \
    applicationstab.cpp

HEADERS  += mainwindow.h \
    objet.h \
    entite.h \
    client.h \
    entreprise.h \
    moteurjeu.h \
    tabdialog.h \
    generaltab.h \
    permissionstab.h \
    applicationstab.h

FORMS    += mainwindow.ui \
    tabdialog.ui \
    generaltab.ui \
    permissionstab.ui \
    applicationstab.ui

CONFIG += c++11
