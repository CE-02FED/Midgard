/*

#ifndef GUIFACADE_H
#define GUIFACADE_H
#include "socketcliente.h"
#include "socketserver.h"
#include "Scene.h"
#include "mythread.h"


class GuiFacade
{
public:
    GuiFacade(Scene* pScene);
    SocketCliente* _socketCliente;
    SocketServer* _socketServer;
    static void* receiveDataFromSocket(string pMensaje);
    static GuiFacade* getInstance();
private:
    static GuiFacade* _facade;
    GuiFacade();
};

#endif // GUIFACADE_H


*/
