#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T23:52:12
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Midgard
TEMPLATE = app
LIBS += -ljsoncpp
CONFIG += C++11
CONFIG += thread



SOURCES += main.cpp\
    mythread.cpp \
    Scene.cpp \
    GuiFacade.cpp \
    socketcliente.cpp \
    socketserver.cpp \
    objectsGui.cpp \
    jsonreadercpp.cpp \
    jsonwritercpp.cpp \
    mainmenu.cpp \
    informationindividual.cpp \
    godsinformation.cpp \
    puebloinformation.cpp \
    clientsocket.cpp \
    serversocket.cpp \
    socket.cpp

HEADERS  += ui_mainwindow.h \
    mythread.h \
    Scene.h \
    GuiFacade.h \
    objectsGui.h \
    Constants.h \
    vector.h \
    jsonreadercpp.h \
    jsonwritercpp.h \
    mainmenu.h \
    informationindividual.h \
    godsinformation.h \
    puebloinformation.h \
    clientsocket.h \
    serversocket.h \
    socket.h \
    SocketException.h

FORMS    += \
    mainmenu.ui \
    informationindividual.ui \
    godsinformation.ui \
    puebloinformation.ui
