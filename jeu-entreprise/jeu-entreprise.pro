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
    entreprise.cpp \
    client.cpp \
    objet.cpp

HEADERS  += mainwindow.h \
    entreprise.h \
    client.h \
    objet.h

FORMS    += mainwindow.ui
