
#include "GuiFacade.h"

//SocketServer* LogicFacade::_socketServer;
GuiFacade* GuiFacade::_facade = 0;
SocketCliente* GuiFacade::_socketClient;


GuiFacade::GuiFacade()
{



}

void GuiFacade::runGui(Scene* pMainGui)
{
    _MainGui = pMainGui;
    _socketClient = new SocketCliente();
    MyThread* _mapThread = new MyThread((void*)askMap,nullptr);
    _socketClient->setMensaje("{\"type\":\"2\", \"Raza\":\"0\", \"IndividuoID\":\"0\"}");
    _mapThread->run();


}

void GuiFacade::askMap()
{
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    _socketClient->setMensaje("{\"type\":\"1\"}");
    pthread_mutex_unlock(&mutex);
    sleep(2);
}

void GuiFacade::receiveDataFromSocket(string pMensaje)
{
        leerJson(pMensaje);
}

void GuiFacade::receiveMap(string pMensaje)
{
    cout << "receiveMap gui"  << endl;
    jsonReaderCpp* Reader = new jsonReaderCpp();
    Vector<int>* matrizMapa = Reader->readMap(pMensaje);
    cout << "gui height: " << matrizMapa->getHeight() << endl;
    _MainGui->setMapActual(matrizMapa);
    cout<< "setio la matriz actual" <<endl;


}

void GuiFacade::receiveGenealogia(string pMensaje)
{
    //Posicion 0= Padre, Posicion 1 = Madre, Posicion 2 = Fitness del individuo
    jsonReaderCpp* Reader = new jsonReaderCpp();
    Vector<int>* vectorFamilia = Reader->readFamily(pMensaje);
    vectorFamilia->print();
    setTmpIdFather(*(*vectorFamilia)[Padre]);
    setTmpIdMother(*(*vectorFamilia)[Madre]);
    setTmpFitness(*(*vectorFamilia)[indvFitness]);
    cout << "receivegenealogia"<< endl;

}

void GuiFacade::getGenealogia(int pRaza, int pIndviduoID)
{
    jsonWriterCpp* crearJson = new jsonWriterCpp();

    _socketClient->setMensaje(crearJson->writeFamilyFromGUI(pRaza,pIndviduoID).c_str());

}

void GuiFacade::setTmpIdFather(int pIdFather)
{
    IdFather = pIdFather;
}

void GuiFacade::setTmpIdMother(int pIdMother)
{
    IdMother = pIdMother;
}

void GuiFacade::setTmpFitness(int pIndvFitness)
{
    IndvFitness = pIndvFitness;
}

int GuiFacade::getTmpIdFather()
{
    return IdFather;
}

int GuiFacade::getTmpIdMother()
{
    return IdMother;
}

int GuiFacade::getTmpFitness()
{
    return IndvFitness;
}

void GuiFacade::getMap()
{
    jsonWriterCpp* crearJson = new jsonWriterCpp();

    _socketClient->setMensaje(crearJson->writeType(1).c_str());
}


void GuiFacade::leerJson(string pMensaje)
{
    cout << "llego al leer gui" << endl;

        jsonReaderCpp* Reader = new jsonReaderCpp();

        switch(Reader->readType(pMensaje))
        {
        case GetMap:
            cout << "paso getMap GUI" << endl;
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


