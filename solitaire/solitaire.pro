#-------------------------------------------------
#
# Project created by QtCreator 2017-04-19T21:47:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = solitaire
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    Card.cpp \
    Deck.cpp \
    Pack.cpp \
    StartPack.cpp \
    TargetPack.cpp \
    WorkPack.cpp \
    GameFacade.cpp

HEADERS  += mainwindow.h \
    Card.h \
    Deck.h \
    Globals.h \
    Pack.h \
    StartPack.h \
    TargetPack.h \
    WorkPack.h \
    GameFacade.h

FORMS    += mainwindow.ui
