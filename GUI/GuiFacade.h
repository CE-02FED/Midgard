#ifndef GUIFACADE_H
#define GUIFACADE_H
#include "socketcliente.h"
#include "socketserver.h"
#include "Scene.h"
#include "iostream"
#include "jsonreadercpp.h"
#include "jsonwritercpp.h"
#include "vector.h"

#define Padre 0
#define Madre 1
#define indvFitness 2
#define GetMap 1
#define Genealogia 2
#define Raza 0
#define individuoID 1

using namespace std;

class SocketCliente;
class GuiFacade
{
public:
    void receiveDataFromSocket(string pMensaje);
    static GuiFacade* getInstance();
    void runGui(Scene* pMainGui);
    Scene* _MainGui;

private:
    static GuiFacade* _facade;
    //SocketCliente* _socketCliente;
    SocketCliente* _socketClient;


    GuiFacade();

    // Metodos para recibir por Socket
    void leerJson(string pMensaje);    
    void receiveMap(string pMensaje);
    void receiveGenealogia(string pMensaje);

    //Metodos para pedir a Lógica
    void getGenealogia(int pRaza, int pIndviduoID);
    void getMap();
};

#endif // GUIFACADE_H



