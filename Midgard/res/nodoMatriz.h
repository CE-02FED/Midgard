
#ifndef NODOMATRIZ_H_
#define NODOMATRIZ_H_

#include <math.h>
#include "nodoMatriz.h"

class NodoMatriz {
private:
    int posX;		//Posicion de la fila
    int posY;		//Posicion de la columna
    int nivel;		//Distancia recorrida
    int prioridad;	//Prioridad en la cola
public:
	NodoMatriz(int pPosX, int pPosY, int pNivel, int pPrioridad);
	~NodoMatriz();
    int getNivel();
    int getPosX();
    int getPosY();
    int getPrioridad();
	void updatePrioridad(int pPosXDestino, int pPosYDestino);
	void elegirDiagonal(int pDireccion);
    int calcularDistancia(int pPosXDestino, int pPosYDestino);
	bool operator<(NodoMatriz nodo);
};

#endif /* NODOMATRIZ_H_ */
