#include "socketcliente.h"
SocketCliente::SocketCliente()
{

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
    info.sin_port = ntohs(7070);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0){
        cout << "conect false menor a 0: "<< connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info)) << endl;

        return false;
    }

    cout << "Conecto"<< endl;
    //pthread_t hilo;
    CrazyThread* hilo = new CrazyThread((void*)SocketCliente::controlador,this);
    hilo->run();
    //pthread_create(&hilo,0,SocketCliente::controlador,(void *)this);
    //pthread_detach(hilo);
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
            char buffer[10] = {0};
            int bytes = recv(padre->descriptor,buffer,10,0);
            mensaje.append(buffer,bytes);
            if(bytes <= 0)
            {
                close(padre->descriptor);
                pthread_exit(NULL);
            }
            if(bytes < 10)
                break;
        }
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
