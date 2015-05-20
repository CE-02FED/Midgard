/**
 *
 */

#ifndef LISTA_H_
#define LISTA_H_
#include <stdlib.h>
#include "nodos.h"
#include <iostream>
using namespace std;
/**
 * Clase lista simple. Es una estructura dinámica de almacenamiento de datos,
 * es genérica por lo que puede
 * almacenar cualquier tipo de datos.
 */
template <typename datoGenerico> class lista {
	private:
		/**	variable para saber el numero de elementos	 */
		int numEle;
		/**	puntero al primer nodo de la lista	 */
		nodo<datoGenerico>* head;
		/**	puntero al ultimo nodo de la lista	 */
		nodo<datoGenerico>* tail;

	public:
		//metodos
		/**metodo que busca una posicion de la lista.
		 * @param pPosicion posicion que se busca en la lista.
		 * @return puntero al nodo buscado.	 */
		nodo<datoGenerico>* getNodo(int pPosicion){ //metodo para obtener un puntero a un nodo
			if (pPosicion<numEle && pPosicion>=0){ //validacion de que no este fuera de rango
				nodo<datoGenerico>* ptrNodoTmp=head; //variable temporal apunta al head
				for(int i=0;i<pPosicion;i++){//mueve la variable temporal el numero de veces necesario
					ptrNodoTmp=(*ptrNodoTmp).getSiguiente();
				}
				return ptrNodoTmp;//retorna el nodo
			}
			else if (numEle!=0){
				cout <<"fuera de rango"<< endl;
				return 0;
			}
			else{
				cout <<"Error, lista vacia "<< endl;
				return 0; ///revisar esto!!!!!!
			}
		}
		datoGenerico* getElemento(int pos){
			nodo<datoGenerico>* nodoTmp=getNodo(pos);
			if(nodoTmp!=0){
				return nodoTmp->getDato();
			}
			else{
				cout<<"error, no se encontro el elemento"<<endl;
				return 0;
			}
		}
		/**
		 * Construcor. Inicializa las variables, y los punteros en nulo.
		 */
		lista(){
            numEle=0; //inicializa el numero de elementos de la lista
            head=0;//inicializa el head en nulo
            tail=0;//inicializa el tail en nulo
		}
		/**
		 * Devuelve el numero de elementos.
		 * @return numEle el numero de elementos.
		 */
		int getNumEle(){
			return numEle;
		}
		/** Agrega un elemento al final de la lista.
		 * Crea un nodo para el elemento, lo mete ahí
		 * y luego inserta el nodo en la lista.
		 * @param elemento el elemento que se quiere ingresar.
		 */
		void agregarFinal(datoGenerico* elemento){//agrega un elemento al final
			nodo<datoGenerico>* nodoInsertar= new nodo<datoGenerico>(elemento);//crea un nodo para el elemento
			if (numEle>0){//cuando hay varios elementos
				(*tail).setSiguiente(nodoInsertar);//al nodo final le pone como siguiente el nodo creado
				tail=nodoInsertar;//se mueve el tail al nuevo nodo
			}
			else if (numEle==0){//si la lista está vacia
				tail=nodoInsertar;//el tail apunta al nodo
				head=tail;//el head apunta al nodo
			}
			else{ //si algo sale mal no hace nada
				return;
			}
			numEle++;//aumenta el numero de elementos
		}
		/**	Agrega un elemento al inicio de la lista. Crea un
		 * nodo para el elemento, lo introduce en el y luego
		 * inserta el nodo el la lista.
		 *  @param elemento el elemento que se desea agregar.
		 */
		void agregarInicio(datoGenerico* elemento){//agrega un elemento al inicio
			nodo<datoGenerico>* nodoInsertar= new nodo<datoGenerico>(elemento);//crea un nodo para el elemento
			if(numEle>0){//si la lista tiene elementos
				(*nodoInsertar).setSiguiente(head);//al nodo creado se le pone siguiente el head
				head=nodoInsertar;//el head apunta al nodo creado
			}
			else if (numEle==0){//si la lista está vacia
				tail=nodoInsertar;//tail apunta al nodo
				head=tail;//head apunta al nodo
			}
			else{//si algo sale mal no hace nada
				return;
			}
			numEle++;//aumenta el numero de elementos
		}
		void agregar(datoGenerico* elemento,int pos){
			if(pos>numEle||pos<0){
				cout<<"metodo agregar fuera de rango"<< endl;
				return;
			}
			else if (pos==0){
				agregarInicio(elemento);
				return;
			}
			else if (pos==numEle){
				agregarFinal(elemento);
				return;
			}
			else{
				nodo<datoGenerico>* nodoInsertar=new nodo<datoGenerico>(elemento);
				nodo<datoGenerico>* nodoAnterior=head;
				for(int i=0; i<pos-1;i++){
					nodoAnterior=nodoAnterior->getSiguiente();
				}
				nodoInsertar->setSiguiente(nodoAnterior->getSiguiente());
				nodoAnterior->setSiguiente(nodoInsertar);
			}
			numEle++;//aumenta el numero de elementos

		}

		/** Elimina el ultimo elemento de la lista. */
		void eliminarFinal(){//elimina el tail
			if (numEle!=0){
					delete tail;//borra el tail
					numEle--;//disminuye el numero de elementos

				if (numEle>0){//luego de eliminar el tail la lista sigue teniendo elementos

					tail=this->getNodo(numEle-1);//el tail es el ultimo
					(*tail).setSiguiente(tail);//el siguiente del tail se pone apuntando a si mismo
					return;
				}
				else {//si luego de borrar el tail no quedan elementos
					head=0;//head apunta a nullo
					tail=0;//tail apunta a nulo
					return;
				}
			}
			else{
				cout<<"lista vacia, no se puede eliminar final"<<endl;
				return;
			}
		}
		/** Elimina el primer elemento de la lista  */
		void eliminarInicio(){//elimina el head
			if (numEle!=0){//si la lista tiene elementos
				if (numEle==1){
					delete head;//elimina el head
					numEle--;//disminuye el numero de elementos
					head=0;//head es nulo
					tail=0;//tail es nulo
					return;
				}
				else{
					nodo<datoGenerico>* nodoTmp=(*head).getSiguiente();//crea un puntero al segundo elemento
					delete head;//elimina el head
					numEle--;//disminuye el numero de elementos
					head=nodoTmp;//el head apunta al segundo elemento
					return;
				}
			}
			else{
				cout<<"lista vacia, no se puede eliminar inicio"<<endl;
				return;
			}
		}
		void eliminar(int pos){
			if (pos==0){
				eliminarInicio();
				return;
			}
			else if (pos==numEle-1){
				eliminarFinal();
				return;
			}
			else{
				if(pos>=numEle||pos<0){
					cout<<"metodo eliminar fuera de rango"<< endl;
					return;
				}
				else{
					nodo<datoGenerico>* nodoAnterior=head;
					for(int i=0; i<pos-1;i++){
						nodoAnterior=nodoAnterior->getSiguiente();
					}
					nodo<datoGenerico>* nodoBorrar=nodoAnterior->getSiguiente();
					nodoAnterior->setSiguiente(nodoBorrar->getSiguiente());
					delete nodoBorrar;
					numEle--;//disminuye el numero de elementos
				}
			}
		}
		/*virtual ~lista(){
			//free(&numEle);
			free(head);
			free(tail);
		}*/

};

#endif /* LISTA_H_ */
