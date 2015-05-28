#ifndef PATHFINDING_H_
#define PATHFINDING_H_
#include "../res/Constants.h"
#include "../res/priorityQueue.h"
#include "../res/nodoMatriz.h"
#include <iostream>
#include "../res/vector.h"
using namespace std;

class Pathfinding {
private:
	short _height;
	short _width;
	Vector<short>* _map;
	Vector<short>* _listaCerrada;
	Vector<short>* _listaAbierta;
	Vector<short>* _listaDireccion;
	string find(int pXInicio, int pYInicio,
				int pXFinal, int pYFinal);
	int calcularPosHorizontal(int pPosX, char pCambio);
	int calcularPosVertical(int pPosY, char pCambio);
	Vector<int>* obtenerRuta(string pRuta, int pPosX, int pPosY);

public:
	Pathfinding(Vector<short> *pMap);
	~Pathfinding();
	Vector<int>* calcularRuta(int pXInicio, int pYInicio,
 	 	 	 	 	 	 	 	 int pXFinal, int pYFinal);

};

#endif /* PATHFINDING_H_ */
