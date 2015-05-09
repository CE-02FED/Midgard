#ifndef GUIFACADE_H
#define GUIFACADE_H
#include "socketcliente.h"
#include "socketserver.h"
#include "Scene.h"



class SocketServer;
class GuiFacade
{
public:
    void receiveDataFromSocket(string pMensaje);
    static GuiFacade* getInstance();
    void runGui(Scene* pMainGui);
private:
    static GuiFacade* _facade;
    //SocketCliente* _socketCliente;
    SocketServer* _socketServer;
    Scene* _MainGui;

    GuiFacade();
    void leerJson(string pMensaje);
    string crearJson(int pType, string pMap, string pGenealogia);
    void getMap();
    void getGenealogia(string pClase, string pID);
};

#endif // GUIFACADE_H



