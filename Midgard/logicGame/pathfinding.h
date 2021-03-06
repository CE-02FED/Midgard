#ifndef PATHFINDING_H_
#define PATHFINDING_H_
#include "../res/Constants.h"
#include "../res/priorityQueue.h"
#include "../res/nodoMatriz.h"
#include <iostream>
#include "../res/vector.h"
#include "Map.h"
using namespace std;

class Pathfinding {
private:
    int _height;
    int _width;
    Vector<int>* _map;
    Vector<int>* _listaCerrada;
    Vector<int>* _listaAbierta;
    Vector<int>* _listaDireccion;
	string find(int pXInicio, int pYInicio,
				int pXFinal, int pYFinal);
	int calcularPosHorizontal(int pPosX, char pCambio);
	int calcularPosVertical(int pPosY, char pCambio);
	Vector<int>* obtenerRuta(string pRuta, int pPosX, int pPosY);

public:
    Pathfinding();
	~Pathfinding();
	Vector<int>* calcularRuta(int pXInicio, int pYInicio,
 	 	 	 	 	 	 	 	 int pXFinal, int pYFinal);

};

#endif /* PATHFINDING_H_ */
