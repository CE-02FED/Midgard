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
void LogicFacade::getGenealogia(string pClase, string pID)
{
     JsonWriter* crearJson = new JsonWriter();
     string* padres = &_MainLogic->getParents(pClase, pID);
     int tmpPadreID =0;
     int tmpMadreID =0;
     string tmpString = "";
     for(int i = 0; i<padres->length(); i++)
     {
         if(padres[i] == "#")
         {
            tmpPadreID= stoi(padres[i]);
            tmpMadreID= stoi(padres[i+1]);
            tmpString = "";
         }
         tmpString = tmpString + padres[i];
     }

     char jsonGetMap;
     crearJson->writeFamily(tmpPadreID,tmpMadreID, 0,jsonGetMap); // Le agrega el string que contiene el ID de ambos padres de pID
    _socketServer->setMensaje(jsonGetMap);
}


/**
 * @brief LogicFacade::leerJson
 * @param pMensaje
 */
void LogicFacade::leerJson(string pMensaje)
{

    /*switch(pMensaje)
    {

    case GetMap:
        getMap();
        break;

    case Genealogia:
        getGenealogia();

        break;

    }*/

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
