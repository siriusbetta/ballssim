#-------------------------------------------------
#
# Project created by QtCreator 2017-09-05T23:23:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NewCustom
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ball.cpp \
    coordinates.cpp \
    ballscontainer.cpp \
    collisions.cpp \
    loggincategories.cpp \
    physicsthread.cpp \
    mainview.cpp \
    simulationscene.cpp \
    coordinatescontainer.cpp

HEADERS += \
        mainwindow.h \
    ball.h \
    coordinates.h \
    ballscontainer.h \
    collisions.h \
    loggingcategories.h \
    physicsthread.h \
    mainview.h \
    simulationscene.h \
    coordinatescontainer.h

FORMS += \
        mainwindow.ui
