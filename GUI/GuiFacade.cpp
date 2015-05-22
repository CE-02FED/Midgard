
#include "GuiFacade.h"

//SocketServer* LogicFacade::_socketServer;
GuiFacade* GuiFacade::_facade = 0;


GuiFacade::GuiFacade()
{



}

void GuiFacade::runGui(Scene* pGuiLogic)
{
    _MainGui = pGuiLogic;    
    _socketClient = new SocketCliente();
}

void GuiFacade::receiveDataFromSocket(string pMensaje)
{
        leerJson(pMensaje);
}

void GuiFacade::receiveMap(string pMensaje)
{
    jsonReaderCpp* Reader = new jsonReaderCpp();
    Vector<int>* matrizMapa = Reader->readMap(pMensaje);

    // Aqui despues le manda la matriz al main gui
}

void GuiFacade::receiveGenealogia(string pMensaje)
{
    //Posicion 0= Padre, Posicion 1 = Madre, Posicion 2 = Fitness del individuo
    jsonReaderCpp* Reader = new jsonReaderCpp();
    Vector<int>* vectorFamilia = Reader->readFamilyFromGUI(pMensaje);

    // AQUI puede llamar algun metodo del main de la gui e insertarle este vector para que ya el haga lo que ocupa

}

void GuiFacade::getGenealogia(int pRaza, int pIndviduoID)
{
    jsonWriterCpp* crearJson = new jsonWriterCpp();

    _socketClient->setMensaje(crearJson->writeFamilyFromGUI(pRaza,pIndviduoID).c_str());

}

void GuiFacade::getMap()
{
    jsonWriterCpp* crearJson = new jsonWriterCpp();

    _socketClient->setMensaje(crearJson->writeType(1).c_str());
}


void GuiFacade::leerJson(string pMensaje)
{
    cout << "llego al leer" << endl;

        jsonReaderCpp* Reader = new jsonReaderCpp();

        switch(Reader->readType(pMensaje))
        {
        case GetMap:
            cout << "paso" << endl;
            receiveMap(pMensaje);

            break;
        case Genealogia:
            receiveGenealogia(pMensaje);
            break;
        default:
            receiveMap(pMensaje);
            break;
        }
}

GuiFacade *GuiFacade::getInstance()
{
    if (_facade == 0)

        _facade = new GuiFacade();

    else
        return _facade;

}


