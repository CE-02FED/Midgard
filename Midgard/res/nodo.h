#ifndef NODE_H
#define NODE_H

#include <iostream>


using namespace std;

//template class vRefList<vRef>;

template<class k>
class Nodo
{
private:
    k _data;
    Nodo* _next;
public:
    Nodo(k);
    void setData(k);
    void setNext(Nodo<k>*);
    k getData();
    Nodo<k>* getNext();
};


template<class k>
Nodo<k>::Nodo(k pdata)
{
    _data = pdata;
    _next = nullptr;
}

template<class k>
void Nodo<k>::setData(k pdata)
{
    _data = pdata;
}

template<class k>
void Nodo<k>::setNext(Nodo<k>* pnext)
{
    _next = pnext;
}

template<class k>
k Nodo<k>::getData()
{
    return _data;
}

template<class k>
Nodo<k>* Nodo<k>::getNext()
{
    return _next;
}

#endif // NODE_H

