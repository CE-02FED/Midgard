#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T23:52:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Midgard
TEMPLATE = app

CONFIG += C++11
CONFIG += thread

SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp \
    individualGui.cpp \
    Scene.cpp \
    GuiFacade.cpp \
    obstacle.cpp \
    quiindividual.cpp \
    socketserver.cpp \
    socketcliente.cpp

HEADERS  += mainwindow.h \
    mythread.h \
    individualGui.h \
    Scene.h \
    GuiFacade.h \
    obstacle.h \
    guiindividual.h \
    socketserver.h \
    socketcliente.h

FORMS    += mainwindow.ui
