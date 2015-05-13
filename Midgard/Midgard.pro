TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
CONFIG += thread
QMAKE_CXXFLAGS += -fpermissive


QT += qml quick widgets
LIBS += -ljsoncpp

SOURCES += main.cpp \
    DataAccess/docXML.cpp \
    DataAccess/pugixml.cpp \
    DataAccess/socketcliente.cpp \
    DataAccess/socketserver.cpp \
    libs/jsonWriter.cpp \
    logicFacade/LogicFacade.cpp \
    logicGame/GameIndividual.cpp \
    logicGeneticAlgorith/Evolution.cpp \
    logicGeneticAlgorith/FitnessCalculation.cpp \
    logicGeneticAlgorith/Individuals.cpp \
    logicGeneticAlgorith/pathfinding.cpp \
    logicGeneticAlgorith/Population.cpp \
    logicRazas/DarkElves.cpp \
    logicRazas/Dwarves.cpp \
    logicRazas/Elves.cpp \
    logicRazas/Giants.cpp \
    res/BitVector.cpp \
    res/crazythread.cpp \
    res/nodoMatriz.cpp \
    res/randomClass.cpp \
    MainLogic.cpp \
    DataAccess/jsonwriter.cpp \
    DataAccess/jsonreader.cpp \
    DataAccess/jsonreadercpp.cpp \
    DataAccess/jsonwritercpp.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    DataAccess/docXML.h \
    DataAccess/pugiconfig.hpp \
    DataAccess/pugixml.hpp \
    DataAccess/socketcliente.h \
    DataAccess/socketserver.h \
    libs/rapidjson/internal/pow10.h \
    libs/rapidjson/internal/stack.h \
    libs/rapidjson/internal/strfunc.h \
    libs/rapidjson/document.h \
    libs/rapidjson/filestream.h \
    libs/rapidjson/prettywriter.h \
    libs/rapidjson/rapidjson.h \
    libs/rapidjson/reader.h \
    libs/rapidjson/stringbuffer.h \
    libs/rapidjson/writer.h \
    libs/jsonWriter.h \
    logicFacade/LogicFacade.h \
    logicGame/GameIndividual.h \
    logicGeneticAlgorith/Evolution.h \
    logicGeneticAlgorith/FitnessCalculation.h \
    logicGeneticAlgorith/Individuals.h \
    logicGeneticAlgorith/pathfinding.h \
    logicGeneticAlgorith/Population.h \
    logicRazas/DarkElves.h \
    logicRazas/Dwarves.h \
    logicRazas/Elves.h \
    logicRazas/Giants.h \
    res/BitVector.h \
    res/Cola.h \
    res/Constants.h \
    res/crazythread.h \
    res/lista_enlazada.h \
    res/nodo.h \
    res/nodoMatriz.h \
    res/priorityQueue.h \
    res/pugiconfig.hpp \
    res/randomClass.h \
    MainLogic.h \
    DataAccess/jsonwriter.h \
    DataAccess/jsonreader.h \
    res/vector.h \
    DataAccess/jsonreadercpp.h \
    DataAccess/jsonwritercpp.h
