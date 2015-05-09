/*

#include "GuiFacade.h"
SocketServer GuiFacade::_socketServer;
GuiFacade* GuiFacade::_facade = 0;

GuiFacade::GuiFacade(Scene* pScene)
{
    _socketServer = new SocketServer();
    //MyThread* newThread = new MyThread((void*)receiveDataFromSocket, nullptr);
    receiveDataFromSocket();
}

void* GuiFacade::receiveDataFromSocket(std::string pMensaje)
{

}

GuiFacade *GuiFacade::getInstance()
{
    if (_facade == 0)

        _facade = new GuiFacade();

    else
        return _facade;

}

*/
