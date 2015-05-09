#ifndef MATRIZ_H_
#define MATRIZ_H_
#include <iostream>
#include <stdlib.h>
#include "Constants.h"
using namespace std;

/**
 * 	@class Matriz
 * 	@brief Clase Matriz:
 * 	Se encarga de manejar una matriz de datos.
 * 	Es de tipo generico, por lo cual acepta distintos tipos de datos.
 */
template<class T> class Matriz {
private:
    T** _matriz;	//Puntero de la matriz.
    short _filas;		//Filas de la matriz.
    short _columnas;	//Columnas de la matriz.

public:
    Matriz(int pFilas, int pColumnas);
    Matriz(int pFilas);
    ~Matriz();
    T* operator[](int pIndex);
    short getHeight();
    short getWidth();
    void print();
    void llenarMatriz(T dato);
};

#endif /* MATRIZ_H_ */

/**
 * 	@brief Constructor
 * 	Crea la matriz para almacenar los datos y genera atributos.
 * 	@param pFilas Numero de filas para la matriz.
 * 	@param pColumnas Numero de columnas para la matriz.
 */
template<class T>
Matriz<T>::Matriz(int pFilas, int pColumnas) {
    _matriz = new T *[pFilas];
    for (int fila = Constants::START; fila < pFilas; fila++) {
        _matriz[fila] = new T[pColumnas];
    }
    _filas = pFilas;
    _columnas = pColumnas;
}

/**
 * 	@brief Constructor sobrecargado
 * 	Crea la matriz unidimensional para almacenar los datos y genera atributos.
 * 	@param pFilas Numero de filas para la matriz.
 */
template<class T>
Matriz<T>::Matriz(int pFilas) {
    _matriz = new T[pFilas];
    _filas = pFilas;
    _columnas = 0;
}

/**
 * 	@brief Destructor
 * 	Destruye los datos almacenados.
 */
template<class T>
Matriz<T>::~Matriz() {
    free(_matriz);
}

/**
 * 	@brief Operador[]
 * 	Permite la capacidad de obtener e ingresar datos por indices
 */
template<class T>
T* Matriz<T>::operator[](int pIndex) {
    return _matriz[pIndex];
}

/**
 * 	@brief Obtener numero de filas
 */
template<class T>
short Matriz<T>::getHeight() {
    return _filas;
}

/**
 * 	@brief Obtener numero de columnas
 */
template<class T>
short Matriz<T>::getWidth() {
    return _columnas;
}

/**
 * 	@brief LLenar la matriz con un dato en particular
 * 	@param dato Dato de tipo template
 */
template<class T>
void Matriz<T>::llenarMatriz(T dato) {
    for (int fila = Constants::START; fila < _filas; fila++) {
        for (int columna = Constants::START; columna < _columnas; columna++) {
            _matriz[fila][columna] = dato;
        }
    }
}

/**
 * 	@brief Imprime la matriz completa en consola.
 */
template<class T>
void Matriz<T>::print() {
    for (int fila = Constants::START; fila < _filas; fila++) {
        for (int columna = Constants::START; columna < _columnas; columna++) {
            cout << _matriz[fila][columna] << "| ";
        }
        cout << endl;
    }
}

