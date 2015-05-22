#include "socketcliente.h"

GuiFacade* SocketCliente::_GuiFacade;
SocketCliente::SocketCliente()
{
    connectar();
}

bool SocketCliente::connectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0){
        cout << "descriptor menor a 0" << descriptor << endl;
        return false;
    }

    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr( IP );
    info.sin_port = ntohs(PUERTO);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0){
        cout << "conect false menor a 0: "<< connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info)) << endl;

        return false;
    }

    cout << "Conecto"<< endl;
    //pthread_t hilo;
    MyThread* hilo = new MyThread((void*)SocketCliente::controlador,this);
    //hilo->run();
    return true;
}


void * SocketCliente::controlador(void *obj)
{
    SocketCliente *padre = (SocketCliente*)obj;
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;

    while (true) {
        pthread_mutex_lock(&mutex);
        string mensaje;
        while (1) {
            char buffer[10000] = {0};
            int bytes = recv(padre->descriptor,buffer,10000,0);
            mensaje.append(buffer,bytes);
            if(bytes <= 0)
            {
                close(padre->descriptor);
                pthread_exit(NULL);
            }
            if(bytes < 10000)
                break;            
        }
        //cout << mensaje << endl;
        _GuiFacade->receiveDataFromSocket(mensaje);
        pthread_mutex_unlock(&mutex);
    }
    close(padre->descriptor);
    pthread_exit(NULL);
}


void SocketCliente::setMensaje(const char *msn)
{


    send(descriptor,msn,strlen(msn),0);
    //cout << "bytes enviados "<< send(descriptor,msn,strlen(msn),0) << endl;
}
