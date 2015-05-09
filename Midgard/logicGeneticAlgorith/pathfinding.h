#ifndef PATHFINDING_H_
#define PATHFINDING_H_
#include "../res/Constants.h"
#include "../res/vector.h"
#include "../res/priorityQueue.h"
#include "../res/nodoMatriz.h"
#include <iostream>
using namespace std;

class Pathfinding {
private:
	short _height;
	short _width;
	Vector<short>* _map;

public:
	Pathfinding(Vector<short> *pMap);
	string find(int pXInicio, int pYInicio,
			int pXFinal, int pYFinal);
	~Pathfinding();
};

#endif /* PATHFINDING_H_ */