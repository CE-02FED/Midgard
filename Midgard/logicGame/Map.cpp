#include "Map.h"

Map* Map::_matrizInstance=0;
Vector<int>* Map::_mapMatriz;
Vector<Individuals>* Map:: _objectMatriz;

Map::Map()
{

    _mapMatriz = new Vector<int>(Constants::getInstance()->WIDTH, Constants::getInstance()->HEIGHT);
    _mapMatriz->llenarMatriz(0);
    _objectMatriz = new Vector<Individuals>(Constants::getInstance()->WIDTH, Constants::getInstance()->HEIGHT);
}

Vector<int>* Map::getMapMatriz()
{
    return _mapMatriz;
}

Vector<Individuals>* Map::getObjectMatriz()
{
    return _objectMatriz;
}

Map *Map::getInstance()
{
    if(_matrizInstance ==0)
        _matrizInstance = new Map();

    return _matrizInstance;



}

void Map::anadirObjeto(int pFila, int pColumna, Individuals *pObjeto, int pElemento)
{
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    (*_mapMatriz)[pFila][pColumna]=pElemento;
    pthread_mutex_unlock(&mutex);
    (*_objectMatriz)[pFila][pColumna]=pObjeto;
}



