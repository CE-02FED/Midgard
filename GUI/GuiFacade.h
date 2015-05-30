#ifndef GUIFACADE_H
#define GUIFACADE_H
#include "socketcliente.h"
#include "socketserver.h"

#include "serversocket.h"
#include "clientsocket.h"
#include "SocketException.h"

#include "Scene.h"
#include "iostream"
#include "jsonreadercpp.h"
#include "jsonwritercpp.h"
#include "vector.h"

#define IP "192.168.0.103"

#define puerto 9090
#define cantFamilia 3
#define Padre 0
#define Madre 1
#define indvFitness 2
#define GetMap 1
#define Genealogia 2
#define Raza 0
#define individuoID 1
#define MAP_SIZE 25
#define Amount_People 2
#define Fittest 0
#define Worst_Fitness 1

using namespace std;
class Scene;
class SocketCliente;
class GuiFacade
{
public:
    void receiveDataFromSocket(string pMensaje);
    static GuiFacade* getInstance();
    void runGui(Scene* pMainGui);
    Scene* _MainGui;
    static void* askMap();
    void getMap();
    void getGenealogia(int pRaza, int pIndviduoID);
    void getPuebloInfo(int pIdPueblo);
    void setTmpIdFather(int pIdFather);
    void setTmpIdMother(int pIdMother);
    void setTmpFitness(int pIndvFitness);
    void setAmountPeople(int pAmountPeople);
    void setFittest(int pFittest);
    void setWorstFitness(int pWorstFitness);
    int getTmpIdFather();
    int getTmpIdMother();
    int getTmpFitness();
    int getAmountPeople();
    int getFittest();
    int getWorstFitness();

private:
    static GuiFacade* _facade;
    //SocketCliente* _socketCliente;
    static ClientSocket* _socketClient;
    int IdFather, IdMother, IndvFitness;
    int _fittest, _worstFitness, _amountPeople;


    GuiFacade();

    // Metodos para recibir por Socket
    void leerJson(string pMensaje);
    void receiveMap(string pMensaje);
    void receiveGenealogia(string pMensaje);
    void receivePuebloInfo(string pMensaje);

};

#endif // GUIFACADE_H



