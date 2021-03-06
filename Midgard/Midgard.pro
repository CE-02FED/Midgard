TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
CONFIG += thread
QMAKE_CXXFLAGS +=


QT += qml quick widgets
LIBS += -ljsoncpp

SOURCES += main.cpp \
    DataAccess/docXML.cpp \
    DataAccess/pugixml.cpp \
    libs/jsonWriter.cpp \
    logicFacade/LogicFacade.cpp \
    logicGame/GameIndividual.cpp \
    logicGame/pathfinding.cpp \
    logicGeneticAlgorith/Evolution.cpp \
    logicGeneticAlgorith/FitnessCalculation.cpp \
    logicGeneticAlgorith/Individuals.cpp \    
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
    DataAccess/jsonwritercpp.cpp \
    res/Constants.cpp \
    res/Random.cpp \
    logicGame/Map.cpp \
    DataAccess/clientsocket.cpp \
    DataAccess/serversocket.cpp \
    DataAccess/socket.cpp \
    DataAccess/connection.cpp \
    res/thread.cpp



RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    DataAccess/docXML.h \
    DataAccess/pugiconfig.hpp \
    DataAccess/pugixml.hpp \
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
    res/Constants.h \
    res/crazythread.h \
    res/nodoMatriz.h \
    res/priorityQueue.h \
    res/pugiconfig.hpp \
    res/randomClass.h \
    MainLogic.h \
    DataAccess/jsonwriter.h \
    DataAccess/jsonreader.h \
    res/vector.h \
    DataAccess/jsonreadercpp.h \
    DataAccess/jsonwritercpp.h \
    res/lista.h \
    res/nodos.h \
    logicGame/pathfinding.h \
    res/Random.h \
    Random/arduino.h \
    Random/randomNumbers.h \
    logicGame/Map.h \
    DataAccess/clientsocket.h \
    DataAccess/serversocket.h \
    DataAccess/socket.h \
    DataAccess/SocketException.h \
    DataAccess/connection.h \
    res/thread.h

OTHER_FILES += \
    res/MidgardConstants.xml
