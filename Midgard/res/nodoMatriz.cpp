#include "nodoMatriz.h"

NodoMatriz::NodoMatriz(int pPosX, int pPosY, int pNivel, int pPrioridad) {
	posX = pPosX;
	posY = pPosY;
	nivel = pNivel;
	prioridad = pPrioridad;
}

int NodoMatriz::getNivel() {
	return nivel;
}

int NodoMatriz::getPosX() {
	return posX;
}

int NodoMatriz::getPosY() {
	return posY;
}

int NodoMatriz::getPrioridad() {
	return prioridad;
}

NodoMatriz::~NodoMatriz()
{
}

/**
 * 	@brief Actualiza la prioridad del nodo en la cola.
 * 		Se realiza por medio de la suma entre:
 * 			nivel + distancia faltante * 10.
 * 	@param pPosXDestino Posicion horizontal final
 * 	@param pPosYDestino Posicion vertical final
 */
void NodoMatriz::updatePrioridad(int pPosXDestino, int pPosYDestino) {
	prioridad = nivel + calcularDistancia(pPosXDestino, pPosYDestino) * 10;
}
/**
 * 	@brief Considera si es mejor usar la diagonal
 * 	@param pDireccion Direccion que desea comprobar
 */
void NodoMatriz::elegirDiagonal(int pDireccion) {
	if (pDireccion % 2 == 0)
		nivel += 10;
	else
		nivel += 14;
}

/**
 * 	@brief Calcula la distancia total hasta el destino
 * 	@param pPosXDestino Posicion horizontal final
 * 	@param pPosYDestino Posicion vertical final
 * 	@return Distancia aproximada hasta el destino
 */
int NodoMatriz::calcularDistancia(int pPosXDestino, int pPosYDestino) {
	static int tmpX, tmpY, distancia;
	tmpX = pPosXDestino - posX;
	tmpY = pPosYDestino - posY;

	// Euclidian Distance
	distancia = (int) (sqrt((tmpX * tmpX) + (tmpY * tmpY)));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//distancia = max(abs(xd), abs(yd));

	return distancia;
}

bool NodoMatriz::operator<(NodoMatriz nodo) {
	return this->getPrioridad() > nodo.getPrioridad();
}
