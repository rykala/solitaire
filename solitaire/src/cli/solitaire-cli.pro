#-------------------------------------------------
#
# Project created by QtCreator 2017-04-19T21:47:57
#
#-------------------------------------------------
BASEDIR = $$PWD/../../

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Target file name
TARGET = hra2017-cli
# Specifies where to put the target file.
DESTDIR = $${BASEDIR}

# Specifies dir for generated files
OBJECTS_DIR = $${BASEDIR}/src/target
MOC_DIR = $${BASEDIR}/src/target

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x
INCLUDEPATH += $${BASEDIR}/src/core

SOURCES += ../core/*.cpp\
           cli-main.cpp\

HEADERS  += ../core/*.h\
