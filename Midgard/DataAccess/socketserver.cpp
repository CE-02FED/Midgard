#include "socketserver.h"

vector<int> SocketServer::clientes;
int SocketServer::descriptor;
sockaddr_in SocketServer::info;
LogicFacade* SocketServer::_LogicFacade;

SocketServer::SocketServer()
{
    CrazyThread* d = new CrazyThread((void*)SocketServer::run,nullptr);
    _LogicFacade = LogicFacade::getInstance();


}


bool SocketServer::crear_Socket()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
    {
        cout << "descriptor server menor a 0" << endl;
        return false;
    }
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(Puerto);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}

bool SocketServer::ligar_kernel()
{
    if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
        return false;

    listen(descriptor,5);
    return true;
}


void* SocketServer::run()
{
    cout << "run" << endl;
    if(!crear_Socket())
        throw string("Error al crear el socket");
    if(!ligar_kernel())
        throw string("Error al  ligar kernel");


    while (true) {
        cout << "Esperando nuevo cliente"<<endl;
        dataSocket data;
        socklen_t tam = sizeof(data.info);
        data.descriptor = accept(descriptor,(sockaddr*)&data.info,&tam);
        if(data.descriptor < 0)
            cout << "Error al acceptar al cliente"<<endl;
        else
        {
            clientes.push_back(data.descriptor);
            /*pthread_t hilo;
            pthread_create(&hilo,0,SocketServer::controladorCliente,(void *)&data);
            pthread_detach(hilo);*/
            CrazyThread * hilo = new CrazyThread((void*)SocketServer::controladorCliente,&data );
            hilo->run();
        }
    }
    close(descriptor);
}



void * SocketServer::controladorCliente(void *obj)
{
    dataSocket *data = (dataSocket*)obj;
    while (true) {
        pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;
        string mensaje;
        while (1) {
             pthread_mutex_lock(&mutex);
            char buffer[100000] = {0};
            int bytes = recv(data->descriptor,buffer,100000,0);
            mensaje.append(buffer,bytes);
            if(bytes < 100000)
                break;
            pthread_mutex_unlock(&mutex);
        }
        //cout << mensaje << endl;
        _LogicFacade->receiveDataFromSocket(mensaje);
        usleep(10000);
    }

    close(data->descriptor);
    pthread_exit(NULL);
}


void SocketServer::setMensaje(const char *msn)
{
    for(unsigned int i = 0 ; i < clientes.size() ; i++)

        send(clientes[i],msn,strlen(msn),0);
        //cout << "bytes enviados "<< send(clientes[i],msn,strlen(msn),0);
}
