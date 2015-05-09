#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbolBinario.h"

template <class k>
class ArbolBinario
{
private:
    /** Raiz del Arbol Binario **/
        NodoArbolBinario<k>* _Root;

public:
        void insertData(k pDato, NodoArbolBinario *pPadre);
        NodoArbolBinario<k> buscarElemento(k pElemento);
};


/**
     * Agrega un nuevo nodo al Arbol
     *
     * @param pDato: informacion del nodo que se va a insertar
     */

template <class k>
void ArbolBinario<k>::insertData(k pDato, NodoArbolBinario* pPadre) {
    
        NodoArbolBinario<k>* nodoTemporal = new NodoArbolBinario<k>(pDato);

        if (_Root == nullptr) {
            _Root = nodoTemporal;
        }
        if(pPadre ==nullptr & _Root== nullptr)
        {
            _Root = nodoTemporal;
        }
        
        else{

            NodoArbolBinario<k> posActual = _Root;
            NodoArbolBinario<k> padre;


            while (true) {

                padre = posActual;

                if(nodoTemporal->getData() >posActualz) > 0){
                    posActual = posActual.getLeft();
                    if(posActual == nullptr){
                        padre.setLeft(nodoTemporal);



                        return;
                    }
                }
                else if(nodoTemporal.compareTo(posActual) < 0){
                    posActual = posActual.getRight();
                    if(posActual == nullptr){
                        padre.setRight(nodoTemporal);
                        return;
                    }
                }
            }
        }
    }

/**
     * Busca un elemento especifico dentro del arbol.
     *
     * @param pElemento: informacion o dato que se desea buscar en el arbol
     * @return El nodo encontrado
     * @throws NullPointerException: cuando el elemento no se ha encontrado
     */
template <class k>
NodoArbolBinario<k> ArbolBinario<k>::buscarElemento(k pElemento)
{

        NodoArbolBinario<k> posActual = _Root;
        NodoArbolBinario<k>* NodoTemporal = new NodoArbolBinario<k>(pElemento);


        while(NodoTemporal.compareTo(posActual) != 0){

            if(NodoTemporal.compareTo(posActual) > 0){ //Si el dato de Nodo Temporal es Mayor que el dato de posicionActual
                posActual = posActual.getLeft();
            }
            else{
                posActual = posActual.getRight();
            }

            if(posActual == nullptr){
                return nullptr;
            }
        }
        return posActual;
    }

#endif // ARBOLBINARIO_H
