
#ifndef NODOMATRIZ_H_
#define NODOMATRIZ_H_

#include <math.h>
#include "nodoMatriz.h"

class NodoMatriz {
private:
	short posX;		//Posicion de la fila
	short posY;		//Posicion de la columna
	short nivel;		//Distancia recorrida
	short prioridad;	//Prioridad en la cola
public:
	NodoMatriz(int pPosX, int pPosY, int pNivel, int pPrioridad);
	~NodoMatriz();
	short getNivel();
	short getPosX();
	short getPosY();
	short getPrioridad();
	void updatePrioridad(int pPosXDestino, int pPosYDestino);
	void elegirDiagonal(int pDireccion);
	short calcularDistancia(int pPosXDestino, int pPosYDestino);
	bool operator<(NodoMatriz nodo);
};

#endif /* NODOMATRIZ_H_ */
