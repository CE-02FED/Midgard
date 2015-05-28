#include <stdlib.h>
#include <iostream>

#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

template<class T>class Node;
template<class T>
class PriorityQueue {
private:
    Node<T>* _head;
    unsigned int lenght;
    void pushNode(Node<T>*);
public:
    PriorityQueue();					//Constructor
    void push(T*);						//Inserta objeto en la cola
    void push(T);						//Inserta objeto en la cola
    void pop();							//Eliminar elemento de la cola
    bool empty();						//Verifica si la cola esta vacia
    int size();							//Retorna tamano de la cola
    T top();							//Extraer elemento de la cola
};

template<class T>
class Node
{
friend class PriorityQueue<T>;

private:
    T* data;
    Node<T> *next;
public:
    Node();
    Node(T *); 							//Constructor
    Node(T); 							//Constructor
    ~Node(); 							//Destructor
    T *getData(); 						//Retorna el dato del objeto
    Node<T> *getNextNode();				//Siguiente nodo
};

/**
 * 	@brief Constructor de la cola
 */
template<class T>
PriorityQueue<T>::PriorityQueue(){
	_head = 0;
	lenght = 0;
}

/**
 * 	@brief Constructor del nodo
 */
template<class T>
Node<T>::Node(){
	data = 0;
	next = 0;
}

/**
 * 	@brief Agrega objeto a la lista
 * 	@param Puntero de objeto a agregar
 */
template<class T>
void PriorityQueue<T>::push(T *dato) {
}

/**
 * 	@brief Agrega objeto a la lista
 * 	@param Objeto a agregar
 */
template<class T>
void PriorityQueue<T>::push(T dato) {
    pushNode(new Node<T>(dato));
}
/**
 * @brief Inserta nodo en la cola de prioridad
 * @param Nodo a agregar
 */
template<class T>
void PriorityQueue<T>::pushNode(Node<T>* node) {
    if (lenght==0) _head = node;
    else
    {
        Node<T> *prevNodeToCompare = 0;
        Node<T> *nodeToCompare = _head;
        for (int i = 0; i < lenght; ++i) {
            T dato = *nodeToCompare->getData();
            if (dato<*node->getData()){
                if (prevNodeToCompare == 0) {
                    node->next = _head;
                    _head = node;
                }
                else{
                    prevNodeToCompare->next = node;
                    node->next = nodeToCompare;
                }
                lenght++;
                return;
            }
            prevNodeToCompare = nodeToCompare;
            nodeToCompare = nodeToCompare->getNextNode();
        }
        prevNodeToCompare->next=node;
    }
    lenght++;
}

/**
 * 	@brief Retrona primer elemento de la cola
 */
template<class T>
T PriorityQueue<T>::top() {
    return *(_head->getData());
}

/**
 * @brief Elimina primer elemento de la cola
 */
template<class T>
void PriorityQueue<T>::pop() {
    Node<T> * headTemp = _head;//Nodo para liberarlo
    _head = _head->getNextNode();
    lenght--;//Actualiza largo
    free(headTemp);//GarbageCollection
}

/**
 * @brief Verifica si esta vacia la cola
 */
template<class T>
bool PriorityQueue<T>::empty() {
    return lenght == 0;
}


/**
 * 	@brief Retorna tamano de la cola
 */
template<class T>
int PriorityQueue<T>::size() {
    return lenght;
}

/**
 * 	@brief Inserta objeto en el nodo
 */
template<class T>
Node<T>::Node(T * t) {
    data = t;
    next = 0;
}

/**
 * 	@Inserta objeto en el nodo
 */
template<class T>
Node<T>::Node(T t) {
    data = static_cast<T*>(malloc(sizeof(T)));
    *data = t;
    next = 0;
}

/**
 * @brief Destructor
 */
template<class T>
Node<T>::~Node() {
    next = 0;
}

/**
 * 	@brief Obtener dato del nodo
 */
template<class T>
T *Node<T>::getData() {
    return data;
}

/**
 * @brief Obtener siguiente nodo
 */
template<class T>
Node<T> *Node<T>::getNextNode() {
    return next;
}

#endif //PROJECTMIDGARD_PRIORITYQUEUE_H
