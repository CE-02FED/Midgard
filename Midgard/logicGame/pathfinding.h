#ifndef PATHFINDING_H_
#define PATHFINDING_H_
#include "Constants.h"
#include "priorityQueue.h"
#include "nodoMatriz.h"
#include <iostream>

#include "vector.h"
using namespace std;

class Pathfinding {
private:
	short _height;
	short _width;
	Vector<short>* _map;
	Vector<short>* _listaCerrada;
	Vector<short>* _listaAbierta;
	Vector<short>* _listaDireccion;

public:
	Pathfinding(Vector<short> *pMap);
	string find(int pXInicio, int pYInicio,
				int pXFinal, int pYFinal);
	~Pathfinding();
	int calcularPosHorizontal(int pPosX, char pCambio);
	int calcularPosVertical(int pPosY, char pCambio);
};

#endif /* PATHFINDING_H_ */
