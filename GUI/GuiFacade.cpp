#include "GuiFacade.h"

//SocketServer* LogicFacade::_socketServer;
GuiFacade* GuiFacade::_facade = 0;
ClientSocket* GuiFacade::_socketClient;
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

GuiFacade::GuiFacade()
{

}

void GuiFacade::runGui(Scene* pMainGui)
{
    _MainGui = pMainGui;
    try{
    _socketClient = new ClientSocket(IP,puerto);
    }
    catch(SocketException&){
        std::cout << "no se pudo conectar" << std::endl;

    }

    MyThread* _mapThread = new MyThread((void*)askMap,nullptr);
    _mapThread->run();


}

void* GuiFacade::askMap()
{
    while(true){
    cout << "estoy GetMapTHREAD" << endl;

    pthread_mutex_lock(&mutex);
    GuiFacade::getInstance()->getMap();
    pthread_mutex_unlock(&mutex);
    sleep(5);
    }
}

void GuiFacade::receiveDataFromSocket(string pMensaje)
{
        leerJson(pMensaje);
}

void GuiFacade::receiveMap(string pMensaje)
{
    cout << "receiveMap gui"  << endl;
    jsonReaderCpp* Reader = new jsonReaderCpp();
    Vector<int>* matrizMapa = new Vector<int>(MAP_SIZE,MAP_SIZE);
    matrizMapa->llenarMatriz(0);
    matrizMapa = Reader->readMap(pMensaje);

    _MainGui->setMap(matrizMapa);
    cout<< "setio la matriz actual" <<endl;

}

void GuiFacade::receiveGenealogia(string pMensaje)
{
    //Posicion 0= Padre, Posicion 1 = Madre, Posicion 2 = Fitness del individuo
    jsonReaderCpp* Reader = new jsonReaderCpp();
    Vector<int>* vectorFamilia = new Vector<int>(cantFamilia);
    vectorFamilia->llenarMatriz(0);
    vectorFamilia = Reader->readFamily(pMensaje);
    vectorFamilia->print();

    setTmpIdFather(*(*vectorFamilia)[Padre]);
    setTmpIdMother(*(*vectorFamilia)[Madre]);
    setTmpFitness(*(*vectorFamilia)[indvFitness]);
    cout << "receivegenealogia"<< endl;

}

void GuiFacade::receivePuebloInfo(string pMensaje)
{
    jsonReaderCpp* Reader = new jsonReaderCpp();
    Vector<int>* vectorPuebloInfo = Reader->readPueblo(pMensaje);
    setAmountPeople(*(*vectorPuebloInfo)[Amount_People]);
    setFittest(*(*vectorPuebloInfo)[Fittest]);
    setWorstFitness(*(*vectorPuebloInfo)[Worst_Fitness]);
    cout << "receivepuebloinfo"<< endl;
}

void GuiFacade::getGenealogia(int pRaza, int pIndviduoID)
{
    jsonWriterCpp* crearJson = new jsonWriterCpp();
    std::string reply;
    try{
    (*_socketClient) << crearJson->writeFamilyFromGUI(pRaza,pIndviduoID);
    (*_socketClient)>> reply;
    }
    catch ( SocketException& ) {
    }
    receiveDataFromSocket(reply);
}


void GuiFacade::getPuebloInfo(int pIdPueblo)
{
    jsonWriterCpp* crearJson = new jsonWriterCpp();
    std::string reply;
    try{
    (*_socketClient)<< crearJson->writePuebloInfo(pIdPueblo).c_str();
    (*_socketClient)>> reply;
    }
    catch ( SocketException& ) {
    }
    receiveDataFromSocket(reply);
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
    std::string reply;
    try{
    (*_socketClient)<<crearJson->writeType(1);
    (*_socketClient)>> reply;
    }
    catch ( SocketException& ) {
    }
    receiveDataFromSocket(reply);

    //_socketClient->setMensaje(crearJson->writeType(1).c_str());
}


void GuiFacade::leerJson(string pMensaje)
{
    cout << "llego al leer gui" << endl;

        jsonReaderCpp* Reader = new jsonReaderCpp();

        switch(Reader->readType(pMensaje))
        {
        case GetMap:            
            receiveMap(pMensaje);

            break;
        case Genealogia:
            receiveGenealogia(pMensaje);
            break;
        default:
            break;
        }
}

void GuiFacade::setAmountPeople(int pAmountPeople)
{
    _amountPeople = pAmountPeople;
}

void GuiFacade::setFittest(int pFittest)
{
    _fittest = pFittest;
}

void GuiFacade::setWorstFitness(int pWorstFitness)
{
    _worstFitness = pWorstFitness;
}

int GuiFacade::getAmountPeople()
{
    return _amountPeople;
}

int GuiFacade::getFittest()
{
    return _fittest;
}

int GuiFacade::getWorstFitness()
{
    return _worstFitness;
}

GuiFacade *GuiFacade::getInstance()
{
    if (_facade == 0)

        _facade = new GuiFacade();

    else
        return _facade;

}


