#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
#include <nodo.h>
#include <iostream>


using namespace std;

template <class k>
class lista_enlazada
{
private:

    int _contador;
    Nodo<k>* _cabeza;
    Nodo<k>* _cola;

public:

    lista_enlazada();

    void add_Dato_Atras(k);
    void eliminar_Dato(k);
    void mostrar_Datos();
    Nodo<k> *getHead();
    int length();
    k getDatabyIndice(int);
};


template<class k>
lista_enlazada<k>::lista_enlazada()
{
    _contador = 0;
    _cabeza = nullptr;
    _cola = nullptr;
}

template<class k>
void lista_enlazada<k>::add_Dato_Atras(k pdata)
{
    Nodo<k>* nuevo_nodo = new Nodo<k>(pdata);


    if(_cabeza == nullptr)
    {

        _contador++;

        _cabeza = nuevo_nodo;
        _cola = _cabeza;

    }
    else
    {
        _contador++;
        _cola->setNext(nuevo_nodo);
        _cola = nuevo_nodo;
    }
}

template<class k>
void lista_enlazada<k>::eliminar_Dato(k pdata)
{
    if(_cabeza == nullptr){
        cout <<"La lista es vacía"<<endl;
        return;
    }

    Nodo<k>* NodoDato = new Nodo<k>(pdata);

    if(_cabeza == NodoDato){
        cout << "borrando cabeza" << endl;
        _cabeza = _cabeza->getNext();
        _contador--;
        return;
    }
    Nodo<k>* NodoActual = _cabeza;

    while(NodoActual != nullptr){

        if(NodoActual->getNext() == _cola)
        {
            _cola = NodoActual;
            _cola->setNext(nullptr);
            _contador--;
            return;
        }
        if(NodoActual->getNext() != _cola && NodoActual->getNext() == NodoDato)
        {
            cout << "hello baby";
            NodoActual->setNext(NodoActual->getNext()->getNext());
            return;
        }
        NodoActual = NodoActual->getNext();
    }
    if(NodoActual == nullptr)
    {
        cout << "El elemento no está en la lista" << endl;
        return;
    }

}

template<class k>
void lista_enlazada<k>::mostrar_Datos()
{
    Nodo<k>* nodoActual = _cabeza;

    for(;nodoActual != 0; nodoActual = nodoActual->getNext()){
        cout << "el dato del nodo " << nodoActual->getData() << endl;
    }
}

template<class k>
k lista_enlazada<k>::getDatabyIndice(int index)
{
    Nodo<k>* current = _cabeza;
    if(index <= _contador)
    {
        for(int i = 0; i < index; i++)
        {
            current = current->getNext();
        }
        return current->getData();
    }
}

template<class k>
Nodo<k>* lista_enlazada<k>::getHead()
{
    return _cabeza;
}


template<class k>
int lista_enlazada<k>::length()
{
    return _contador;
}

#endif // LISTA_ENLAZADA_H
