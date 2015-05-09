#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include "mythread.h"
#include "GuiFacade.h"

#define Puerto 9090


using namespace std;


struct dataSocket{
    int descriptor;
    sockaddr_in info;
};

class GuiFacade;
class SocketServer
{
public:
    SocketServer();
    static void *run();
    void setMensaje(const char *msn);
private:
    static int descriptor;
    static sockaddr_in info;
    static GuiFacade* _GuiFacade;
    static bool crear_Socket();
    static bool ligar_kernel();
    static void * controladorCliente(void *obj);
    static vector<int> clientes;
};

#endif // SOCKETSERVER_H
