#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <stdlib.h>
#include "Constants.h"
using namespace std;

/**
 * 	@class Vector
 * 	@brief Clase Matriz:
 * 	Se encarga de manejar una matriz de datos.
 * 	Es de tipo generico, por lo cual acepta distintos tipos de datos.
 */
template<class T> class Vector {
private:
    T** _matriz;	//Puntero de la matriz.
    T* _arreglo;   //Puntero del arreglo
    int _filas;		//Filas de la matriz.
    int _columnas;	//Columnas de la matriz.
    bool _matrizFlag = true;

public:
    Vector(int pFilas, int pColumnas);
    Vector(int pFilas);
    ~Vector();
    T* operator[](int pIndex);
    int lenght();
    int getHeight();
    int getWidth();
    void print();
    void llenarMatriz(T dato);
    void printArray();
};

/**
 * 	@brief Constructor
 * 	Crea la matriz para almacenar los datos y genera atributos.
 * 	@param pFilas Numero de filas para la matriz.
 * 	@param pColumnas Numero de columnas para la matriz.
 */
template<class T>
Vector<T>::Vector(int pFilas, int pColumnas) {
    _matriz = new T *[pFilas];
    for (int fila = Constants::START; fila < pFilas; fila++) {
        _matriz[fila] = new T[pColumnas];
    }
    _filas = pFilas;
    _columnas = pColumnas;
    _arreglo =0;
    _matrizFlag = true;
}

/**
 * 	@brief Constructor sobrecargado
 * 	Crea la matriz unidimensional para almacenar los datos y genera atributos.
 * 	@param pTamano Tamano del arreglo.
 */
template<class T>
Vector<T>::Vector(int pTamano) {
    _arreglo = new T[pTamano];
    _filas = pTamano;
    _columnas = 0;
    _matriz=0;
    _matrizFlag = false;
}

/**
 * 	@brief Obtener tamano de arreglo
 * 	@return Tamano de arreglo
 */
template<class T>
int Vector<T>::lenght() {
    return _filas;
}

/**
 * 	@brief Destructor
 * 	Destruye los datos almacenados.
 */
template<class T>
Vector<T>::~Vector() {
    free(_matriz);
}

/**
 * 	@brief Operador[]
 * 	Permite la capacidad de obtener e ingresar datos por indices
 * 	@return Dato almacenado en la matriz
 */
template<class T>
T* Vector<T>::operator[](int pIndex) {
    if(_matrizFlag) {
		return _matriz[pIndex];
	} else {
		return &(_arreglo[pIndex]);
	}

}

/**
 * 	@brief Obtener numero de filas
 * 	@return Numero de filas
 */
template<class T>
int Vector<T>::getHeight() {
    return _filas;
}

/**
 * 	@brief Obtener numero de columnas
 * 	@return Numero de columnas
 */
template<class T>
int Vector<T>::getWidth() {
    return _columnas;
}

/**
 * 	@brief LLenar la matriz con un dato en particular
 * 	@param dato Dato de tipo template
 */
template<class T>
void Vector<T>::llenarMatriz(T dato) {
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
void Vector<T>::print() {
    for (int fila = Constants::START; fila < _filas; fila++) {
        for (int columna = Constants::START; columna < _columnas; columna++) {
            cout << _matriz[fila][columna] << "| ";
        }
        cout << endl;
    }
}

template<class T>
void Vector<T>::printArray() {
    for (int fila = Constants::START; fila < _filas; fila++) {
            cout << _arreglo[fila]<< "| ";
        cout << endl;
    }
}


#endif /* VECTOR_H_ */
