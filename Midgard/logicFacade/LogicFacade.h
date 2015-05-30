#ifndef LOGICFACADE_H
#define LOGICFACADE_H

#include "../DataAccess/serversocket.h"
#include "../DataAccess/clientsocket.h"
#include"../DataAccess/serversocket.h"
#include "../DataAccess/SocketException.h"
#include"../DataAccess/connection.h"
#include "../res/crazythread.h"
#include "iostream"
#include "../MainLogic.h"
#include "../DataAccess/jsonwriter.h"
#include "../DataAccess/jsonreader.h"
#include "../DataAccess/jsonreadercpp.h"
#include "../DataAccess/jsonwritercpp.h"

#define Padre 0
#define Madre 1
#define indvFitness 2
#define GetMap 1
#define Genealogia 2
#define PuebloInfo 4
#define Raza 0
#define individuoID 1




using namespace std;


class connection;
class LogicFacade
{
public:
    string receiveDataFromSocket(string pMensaje);
    static LogicFacade* getInstance();
    void runLogic(MainLogic* pMainLogic);
    string getMap();

private:
    static LogicFacade* _facade;
    ClientSocket* _socketCliente;
    connection* _socketServer;
    MainLogic* _MainLogic;
    jsonWriterCpp* crearJson;
    jsonReaderCpp* Reader;

    LogicFacade();
    string leerJson(string pMensaje);
    string getGenealogia(Vector<int> *pDatos);
    string getPuebloInfo(string pPueblo);
};

#endif // LOGICFACADE_H
