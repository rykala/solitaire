#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T12:39:47
#
#-------------------------------------------------

BASEDIR = $$PWD/../../

QT += core gui
QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Target file name
TARGET = hra2017
# Specifies where to put the target file.
DESTDIR = $${BASEDIR}

# Specifies dir for generated files
OBJECTS_DIR = $${BASEDIR}/src/target
MOC_DIR = $${BASEDIR}/src/target

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x
INCLUDEPATH += $${BASEDIR}/src/core

SOURCES +=  ../core/*.cpp\
            main.cpp\
            GraphicCard.cpp \
            GraphicDeck.cpp \
            mainwindow.cpp \
            GraphicGameBoard.cpp


HEADERS  += ../core/*.h\
            GraphicCard.h \
            GraphicDeck.h \
            mainwindow.h \
            GraphicGameBoard.h


RESOURCES = resources.qrc \

FORMS += \
    mainwindow.ui
