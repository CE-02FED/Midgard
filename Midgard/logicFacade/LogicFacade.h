#ifndef LOGICFACADE_H
#define LOGICFACADE_H

#include "../DataAccess/socketcliente.h"
#include "../DataAccess/socketserver.h"
#include "../res/crazythread.h"
#include "iostream"
#include "../MainLogic.h"
#include "../DataAccess/jsonwriter.h"

#define Madre 1
#define Padre 0
#define GetMap 1
#define Genealogia 2




using namespace std;


class SocketServer;
class LogicFacade
{
public:
    void receiveDataFromSocket(string pMensaje);
    static LogicFacade* getInstance();
    void runLogic(MainLogic* pMainLogic);
private:
    static LogicFacade* _facade;
    SocketCliente* _socketCliente;
    SocketServer* _socketServer;
    MainLogic* _MainLogic;

    LogicFacade();
    void leerJson(string pMensaje);
    void getMap();
    void getGenealogia(string pClase, string pID);
};

#endif // LOGICFACADE_H
