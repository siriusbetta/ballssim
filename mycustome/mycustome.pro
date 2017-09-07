#-------------------------------------------------
#
# Project created by QtCreator 2017-09-07T11:26:39
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT		 += testlib

TARGET = mycustome
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    testcoordinates.cpp \
    testcoordinatescontainer.cpp
SOURCES += ../coordinates.cpp
SOURCES += ../coordiantescontainer.cpp

HEADERS += \
    testcoordinates.h \
    testcoordinatescontainer.h
