#-------------------------------------------------
#
# Project created by QtCreator 2017-04-19T12:29:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SolitaireICP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    StartPack.cpp \
    Pack.cpp \
    Deck.cpp \
    Card.cpp \
    WorkPack.cpp \
    TargetPack.cpp

HEADERS  += mainwindow.h \
    StartPack.h \
    Pack.h \
    Deck.h \
    Card.h \
    WorkPack.h \
    Globals.h \
    TargetPack.h

FORMS    += mainwindow.ui
