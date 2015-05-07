TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
CONFIG += thread
QMAKE_CXXFLAGS += -fpermissive


SOURCES += main.cpp \
    Population.cpp \
    BitVector.cpp \
    Evolution.cpp \
    FitnessCalculation.cpp \
    Individuals.cpp \
    docXML.cpp \
    pugixml.cpp \
    Elves.cpp \
    DarkElves.cpp \
    Giants.cpp \
    Dwarves.cpp \
    GameIndividual.cpp \
    randomClass.cpp \
    socketserver.cpp \
    socketcliente.cpp \
    crazythread.cpp \
    LogicFacade.cpp \
    MainLogic.cpp

OTHER_FILES += \
    deployment.pri \
    MidGard.pro.user \
    MIdgard.pro.user

HEADERS += \
    Population.h \
    BitVector.h \
    Evolution.h \
    FitnessCalculation.h \
    Individuals.h \
    Constants.h \
    docXML.h \
    lista_enlazada.h \
    nodo.h \
    Cola.h \
    NodoArbolBinario.h \
    ArbolBinario.h \
    Elves.h \
    DarkElves.h \
    Giants.h \
    GameIndividual.h \
    randomClass.h \
    matriz.h \
    Dwarves.h \
    socketserver.h \
    socketcliente.h \
    crazythread.h \
    LogicFacade.h \
    MainLogic.h

