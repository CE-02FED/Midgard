#ifndef MAP_H
#define MAP_H

#include "../res/vector.h"
#include "../logicGeneticAlgorith/Individuals.h"
#include "../res/Constants.h"

class Map
{
private:
    static Map* _matrizInstance;
    Map();
    static Vector<int>* _mapMatriz;
    static Vector<Individuals>* _objectMatriz;





public:
    static Map* getInstance();
    void anadirObjeto(int pFila, int pColumna, int pObjeto, int pElemento);
    Vector<int> *getMapMatriz();
    Vector<Individuals> *getObjectMatriz();


};

#endif // MAP_H
