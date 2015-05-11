#include "LogicFacade.h"

//SocketServer* LogicFacade::_socketServer;
LogicFacade* LogicFacade::_facade = 0;


LogicFacade::LogicFacade()
{
}

void LogicFacade::runLogic(MainLogic* pMainLogic)
{
    _MainLogic = pMainLogic;
    _socketServer = new SocketServer();

}

/**
 * @brief LogicFacade::receiveDataFromSocket
 * Recibe el dato por socket y lo interpreta mediante el metodo leerJson
 * @param pMensaje: Mensaje recibido por socket
 */
void LogicFacade::receiveDataFromSocket(string pMensaje)
{
    leerJson(pMensaje);
}

/**
 * @brief LogicFacade::getMap
 * Se le envia el json del tipo mapa por socket
 */
void LogicFacade::getMap()
{
    JsonWriter* crearJson = new JsonWriter();
    char pArreglo[10000];
    crearJson->writeMap(_MainLogic->getMap(),pArreglo);
    _socketServer->setMensaje(pArreglo);
}

/**
 * @brief LogicFacade::getGenealogia
 * @param pClase: Del individuo al que se desea saber su genealogia
 * @param pID: El ID del individuo
 */
void LogicFacade::getGenealogia(Vector<int> pDatos)
{
     JsonWriter* crearJson = new JsonWriter();
     Vector<int>* padres = _MainLogic->getParents(pDatos[Raza],pDatos[individuoID]);

     char pArreglo[10000];
     crearJson->writeFamily((*padres)[Padre],(*padres)[Madre], (*padres)[indvFitness],pArreglo); // Le agrega el string que contiene el ID de ambos padres de pID
    _socketServer->setMensaje(pArreglo);
}


/**
 * @brief LogicFacade::leerJson
 * @param pMensaje
 */
void LogicFacade::leerJson(string pMensaje)
{
    try {
        jsonReader* Reader = new jsonReader();


        switch(Reader->readType(pMensaje))
        {
        case GetMap:
            cout << "paso" << endl;
            getMap();
            break;
        case Genealogia:
            getGenealogia(Reader->readFamilyFromGUI(pMensaje));
            break;
        default:
            getMap();
            break;
        }

    } catch (...) {
        cout << "Fallo" << endl;
        exit(EXIT_FAILURE);
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

    else
        return _facade;

}
