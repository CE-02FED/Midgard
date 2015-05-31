#include "LogicFacade.h"

//SocketServer* LogicFacade::_socketServer;
LogicFacade* LogicFacade::_facade = 0;


LogicFacade::LogicFacade()
{
}

void LogicFacade::runLogic(MainLogic* pMainLogic)
{
    _MainLogic = pMainLogic;    
    _socketServer = new connection();
    _socketServer->start();

    //receiveDataFromSocket("{\"type\":\"1\"}");
//{"type":"1"}"{\"type\":\"1\"}"
}

/**
 * @brief LogicFacade::receiveDataFromSocket
 * Recibe el dato por socket y lo interpreta mediante el metodo leerJson
 * @param pMensaje: Mensaje recibido por socket
 */
string LogicFacade::receiveDataFromSocket(string pMensaje)
{
    return leerJson(pMensaje);
}

/**
 * @brief LogicFacade::getMap
 * Se le envia el json del tipo mapa por socket
 */
string LogicFacade::getMap()
{

    crearJson = new jsonWriterCpp();

    cout << "llegoGetMap Logic" << endl;
    cout << "manda mapa from logic" << endl;    
    return (crearJson->writeMap((_MainLogic->getMap())).c_str());

}

/**
 * @brief LogicFacade::getGenealogia
 * @param pClase: Del individuo al que se desea saber su genealogia
 * @param pID: El ID del individuo
 */
string LogicFacade::getGenealogia(Vector<int>* pDatos)
{
     crearJson = new jsonWriterCpp();
     Vector<int>* padres = new Vector<int>(3);

     padres = _MainLogic->getParents((*pDatos)[Raza],(*pDatos)[individuoID]);

     return (crearJson->writeFamily(*(*padres)[Padre],*(*padres)[Madre], *(*padres)[indvFitness]).c_str());
}

string LogicFacade::getPuebloInfo(string pPueblo)
{
    Reader = new jsonReaderCpp();
    Vector<int>* tipoPueblo =Reader->readPubloInfo(pPueblo);

    crearJson = new jsonWriterCpp();

    tipoPueblo= _MainLogic->getPuebloInfo(*(*tipoPueblo)[0]);

    return (crearJson->writePuebloInfo(*(*tipoPueblo)[1],*(*tipoPueblo)[0],*(*tipoPueblo)[2]).c_str());
}




/**
 * @brief LogicFacade::leerJson
 * @param pMensaje
 */
string LogicFacade::leerJson(string pMensaje)
{
    cout << "llego al leer logica" << endl;

        Reader = new jsonReaderCpp();

        switch(Reader->readType(pMensaje))
        {
        case GetMap:
            cout << "paso getMap logic" << endl;
             return getMap();
            break;
        case Genealogia:
            return getGenealogia(Reader->readFamilyFromGUI(pMensaje));
            break;
        case PuebloInfo:
            return getPuebloInfo(pMensaje);
            break;

        default:
            getMap();
            break;
        }    
}
/**
 * @brief LogicFacade::getInstance
 * Devuelve la unica instancia posible de esta clase
 * y si aun no ha sido creada este la crea y retorna un puntero de la clase
 * @return: Devuelve un puntero de la instancia de la clase
 */
LogicFacade *LogicFacade::getInstance()
{
    if (_facade == 0)

        _facade = new LogicFacade();

        return _facade;

}
