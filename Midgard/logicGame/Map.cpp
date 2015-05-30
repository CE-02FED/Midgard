#include "Map.h"

Map* Map::_matrizInstance=0;
Vector<int>* Map::_mapMatriz;
Vector<Individuals>* Map:: _objectMatriz;
pthread_mutex_t mutex;

Map::Map()
{
        _mapMatriz = new Vector<int>(Constants::getInstance()->WIDTH, Constants::getInstance()->HEIGHT);
        _mapMatriz->llenarMatriz(0);
        _objectMatriz = new Vector<Individuals>(Constants::getInstance()->WIDTH, Constants::getInstance()->HEIGHT);

        _mapMatriz = initMatriz();              
}

Vector<int> *Map::initMatriz()
{
   // pthread_mutex_lock(&mutex);
    int Height = Constants::getInstance()->HEIGHT;
    int Width = Constants::getInstance()->WIDTH;

    string tmpMap=Constants::getInstance()->MATRIZ;    

    Vector<int>* newMatriz = new Vector<int>(Height, Width) ;

        string numero = "";
        int index = 0, jindex = 0;
        for (int i = 0; i < tmpMap.length(); i++) {
            if (index >= Height) {
                break;
            }
            if (jindex >= Width) {
                jindex = 0;
                index++;
            }
            if (tmpMap[i] == '#') {
                (*newMatriz)[index][jindex] = stoi(numero);
                jindex++;
                numero = "";
            }
            else {
                numero += tmpMap[i];
            }
        }
   //pthread_mutex_unlock(&mutex);
  return newMatriz;

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
    pthread_mutex_lock(&mutex);
    if(_matrizInstance == 0)
        _matrizInstance = new Map();

    pthread_mutex_unlock(&mutex);
    return _matrizInstance;
}

void Map::anadirObjeto(int pFila, int pColumna, Individuals* pObjeto, int pElemento)
{
    pthread_mutex_lock(&mutex);
    (*_mapMatriz)[pFila][pColumna]=pElemento;        
    (*_objectMatriz)[pFila][pColumna] = *pObjeto;
    pthread_mutex_unlock(&mutex);
}



