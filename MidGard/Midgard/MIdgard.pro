TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
CONFIG += thread


SOURCES += main.cpp \
    Population.cpp \
    BitVector.cpp \
    Evolution.cpp \
    FitnessCalculation.cpp \
    Individuals.cpp \
    docXML.cpp \
    pugixml.cpp

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
    nodo.h

