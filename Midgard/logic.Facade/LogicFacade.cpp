#include "LogicFacade.h"

//SocketServer* LogicFacade::_socketServer;
LogicFacade* LogicFacade::_facade = 0;


LogicFacade::LogicFacade(MainLogic* pMainLogic)
{
        _socketServer = new SocketServer();
        _MainLogic = pMainLogic;

}


void LogicFacade::receiveDataFromSocket(string pMensaje)
{
    leerJson(pMensaje);
}

void LogicFacade::getMap()
{
    string jsonGetMap = crearJson(GetMap,_MainLogic->getMap(),nullptr);
    _socketServer->setMensaje(jsonGetMap.c_str());
}

void LogicFacade::getGenealogia(string pClase, string pID)
{
    string jsonGetMap = crearJson(Genealogia,nullptr, _MainLogic->getParents(pClase, pID)); // Le agrega el string que contiene el ID de ambos padres de pID
    _socketServer->setMensaje(jsonGetMap.c_str());
}



void LogicFacade::leerJson(string pMensaje)
{
    switch(pMensaje)
    {

    case GetMap:
        getMap();
        break;

    case Genealogia:
        getGenealogia();

        break;

    }
}

string LogicFacade::crearJson(int pType, string pMap, string pGenealogia)
{
    switch (pType)
    {
    case GetMap:
        break;
    case Genealogia:
        break;
    }
}



LogicFacade *LogicFacade::getInstance()
{
    if (_facade == 0)

        _facade = new LogicFacade();

    else
        return _facade;

}
