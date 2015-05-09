
#include "GuiFacade.h"

//SocketServer* LogicFacade::_socketServer;
GuiFacade* GuiFacade::_facade = 0;


GuiFacade::GuiFacade()
{



}

void GuiFacade::runGui(Scene* pGuiLogic)
{
    _MainGui = pGuiLogic;
}

void GuiFacade::receiveDataFromSocket(string pMensaje)
{
    leerJson(pMensaje);
    _socketServer = new SocketServer();
}

void GuiFacade::getMap()
{
    //string jsonGetMap = crearJson(GetMap,_MainLogic->getMap(),nullptr);
    _socketServer->setMensaje(jsonGetMap.c_str());
}

void GuiFacade::getGenealogia(string pClase, string pID)
{
    //string jsonGetMap = crearJson(Genealogia,nullptr, _MainLogic->getParents(pClase, pID)); // Le agrega el string que contiene el ID de ambos padres de pID
    _socketServer->setMensaje(jsonGetMap.c_str());
}



void GuiFacade::leerJson(string pMensaje)
{
   /* switch(pMensaje)
    {

    case GetMap:
        getMap();
        break;

    case Genealogia:
        getGenealogia();

        break;

    }*/
}

string GuiFacade::crearJson(int pType, string pMap, string pGenealogia)
{/*
    switch (pType)
    {
    case GetMap:
        break;
    case Genealogia:
        break;
    }*/
}



GuiFacade *GuiFacade::getInstance()
{
    if (_facade == 0)

        _facade = new GuiFacade();

    else
        return _facade;

}

