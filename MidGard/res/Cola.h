#ifndef COLA_H
#define COLA_H
#include "nodo.h"

/* Plantilla de clase cola */
template <class k>
class Cola
{
private:
    Nodo<k> * _Start,* _End; /* Apuntadores al inicio y al final de la cola */
    int _Length; /* Longitud actual de la cola */
public:
    Cola(); /* Constructora */
    ~Cola(); /* Destructora */
    void push(k); /* Encola un elemento */
    k pop(void); /* Desencola un elemento */
    int Length(void); /* Devuelve longitud de la cola */
    void display(void); /* Muestra la cola */
    bool isEmpty(void);
};

template <class k>
Cola<k>::Cola()
{
    _Start = _End = nullptr;
    _Length = 0;
}

template <class k>
void Cola<k>::push(k value){
    Nodo<k> * newNode = new Nodo<k>(value);
    newNode->setData(value);
    if(_Start==nullptr)
    {
        _Start = newNode;
        _End = newNode;
        newNode->setNext(nullptr);
        _Length++;
    }
    else
    {
        _End->setNext(newNode);
        newNode->setNext(nullptr);
        _End = newNode;
        _Length++;
    }
}

template <class k>
k Cola<k>::pop(){
    k value;
    if(_Start==nullptr)
        return -1;
    else
    {
        value = _Start->getData();
        _Start = _Start->getNext();
        _Length--;
    }
    return value;
}

template <class k>
int Cola<k>::Length()
{
    return _Length;
}

template <class k>
bool Cola<k>::isEmpty(){
    if(_Start == nullptr)
        return true;
    else
        return false;
}

template <class k>
void Cola<k>::display(){
    if(_Start==nullptr)
    std::cout << "NO DATA";
    else
    {
        for(Nodo<int> * tmpSearcher = _Start;tmpSearcher != nullptr;tmpSearcher = tmpSearcher->getNext())
        {
            std::cout << tmpSearcher->getData() << ", ";
        }
    }
}
#endif
