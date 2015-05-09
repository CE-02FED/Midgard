#ifndef PATHFINDING_H_
#define PATHFINDING_H_
#include "Constants.h"
#include "matriz.h"
#include "priorityQueue.h"
#include "nodoMatriz.h"
#include <iostream>
using namespace std;

class Pathfinding {
private:
	short _height;
	short _width;
	Matriz<short>* _map;

public:
	Pathfinding(Matriz<short> *pMap);
	string find(int pXInicio, int pYInicio,
			int pXFinal, int pYFinal);
	~Pathfinding();
};

#endif /* PATHFINDING_H_ */
