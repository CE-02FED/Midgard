#ifndef LOGICFACADE_H
#define LOGICFACADE_H

#include "socketcliente.h"
#include "socketserver.h"
#include "crazythread.h"
#include "iostream"
#include "MainLogic.h"

#define jSonKeyGetMap "getMap"
#define jSonKeyGetGenealogia "Familia"
#define GetMap 1
#define Genealogia 2




using namespace std;


class SocketServer;
class LogicFacade
{
public:
    void receiveDataFromSocket(string pMensaje);
    static LogicFacade* getInstance();
private:
    static LogicFacade* _facade;
    SocketCliente* _socketCliente;
    SocketServer* _socketServer;
    MainLogic* _MainLogic;

    LogicFacade(MainLogic *pMainLogic);
    void leerJson(string pMensaje);
    string crearJson(int pType, string pMap, string pGenealogia);
    void getMap();
    void getGenealogia(string pClase, string pID);
};

#endif // LOGICFACADE_H
