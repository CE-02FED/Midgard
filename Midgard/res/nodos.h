/*
 * nodo.h
 *
 *  Created on: 26/2/2015
 *      Author: fernando
 */

#ifndef NODO_H_
#define NODO_H_
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename datoGenerico> class nodo {
	private:
		datoGenerico* datoContenido; //dato del nodo
		nodo* siguiente; //puntero al siguiente nodo
	public:
		nodo(datoGenerico* pDato){//constructor
					datoContenido=pDato;
					siguiente=this;
		}
		virtual ~nodo(){ //destructor
			//cout << "destruye nodo"<< endl;
			//cout <<&datoContenido << endl;
			//free(&datoContenido);
			//free(&siguiente);

		}

		//sets y gets
		datoGenerico* getDato(){
			return datoContenido;
		}
		void setSiguiente(nodo* ptrNodo){
			siguiente=ptrNodo;
		}
		nodo* getSiguiente(){
			return siguiente;
		}
};

#endif /* NODO_H_ */
