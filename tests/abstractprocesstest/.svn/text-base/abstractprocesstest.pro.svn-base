#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T13:39:35
#
#-------------------------------------------------
include(../../common.pri )
include(../../app.pri )

QT       += network testlib xml
QT       -= gui

TARGET = abstractprocesstest
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle

VERSION=1.0.0
DEFINES += VERSION=\'\"$${VERSION}\"\' TYPE=0

INCLUDEPATH += ../../src/abstractprocess

HEADERS += ../../src/abstractprocess/abstractprocess.h

SOURCES += abstractprocesstest.cpp \
           ../../src/abstractprocess/abstractprocess.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -lframework$${LIB_SUFFIX}
