#-------------------------------------------------
#
# Project created by QtCreator 2017-04-19T21:47:57
#
#-------------------------------------------------
BASEDIR = $$PWD/../..

QT += core

# Target file name
TARGET = hra2017-cli
# Specifies where to put the target file.
DESTDIR = $${BASEDIR}

# Specifies dir for generated files
OBJECTS_DIR = $${BASEDIR}/src/target
MOC_DIR = $${BASEDIR}/src/target

TEMPLATE = app
DEFINES += QT_NO_DEBUG_OUTPUT
QMAKE_CXXFLAGS += -std=c++0x
INCLUDEPATH += $${BASEDIR}/src/core

SOURCES += ../core/*.cpp\
           cli-main.cpp\
    CliGameBoard.cpp

HEADERS  += ../core/*.h\
    CliGameBoard.h
