#ifndef LOGICFACADE_H
#define LOGICFACADE_H

#include "../DataAccess/socketcliente.h"
#include "../DataAccess/socketserver.h"
#include "../res/crazythread.h"
#include "iostream"
#include "../MainLogic.h"
#include "../DataAccess/jsonwriter.h"
#include "../DataAccess/jsonreader.h"

#define Padre 0
#define Madre 1
#define indvFitness 2
#define GetMap 1
#define Genealogia 2
#define Raza 0
#define individuoID 1




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
    void getGenealogia(Vector<int> pDatos);
};

#endif // LOGICFACADE_H
