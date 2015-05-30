#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "GuiFacade.h"

#define IP "192.168.0.100"
#define PUERTO 9090

using namespace std;

class MyThread;
class GuiFacade;
class SocketCliente
{
public:
    SocketCliente();
    bool connectar();
    void setMensaje(const char *msn);
    void matarHilo();
private:

    static GuiFacade* _GuiFacade;
    int descriptor;
    sockaddr_in info;
    static void * controlador(void *obj);
};

#endif // SOCKETCLIENTE_H
