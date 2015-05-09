#ifndef NODOARBOLBINARIO_H
#define NODOARBOLBINARIO_H

template<class k>
class NodoArbolBinario
{
private:
private:
    NodoArbolBinario<k>* _leftSon;
    NodoArbolBinario<k>* _rightSon;
    k _Dato;
public:
    NodoArbolBinario(k pdata);
    void setDato(k pDato);
    void setLeft(NodoArbolBinario<k>* pLeft);
    void setRight(NodoArbolBinario<k>* pRight);
    NodoArbolBinario<k>* getLeft();
    NodoArbolBinario<k>* getRight();

    k getData();
    Nodo<k>* getNext();

};

template<class k>
NodoArbolBinario<k>::NodoArbolBinario(k pdata)
{
    _Dato = pdata;
    _leftSon = nullptr;
    _rightSon = nullptr;
}

template<class k>
void NodoArbolBinario<k>::setDato(k pDato)
{
    _Dato = pDato;
}

template<class k>
void NodoArbolBinario<k>::setLeft(NodoArbolBinario<k>* pLeft)
{
    _leftSon = pLeft;
}

template<class k>
void NodoArbolBinario<k>::setRight(NodoArbolBinario<k>* pRight)
{
     _rightSon= pRight;
}

template<class k>
k NodoArbolBinario<k>::getData()
{
    return _Dato;
}

template<class k>
NodoArbolBinario<k>* NodoArbolBinario<k>::getRight()
{
    return _rightSon;
}

template<class k>
NodoArbolBinario<k>* NodoArbolBinario<k>::getLeft()
{
    return _leftSon;
}





#endif // NODOARBOLBINARIO_H
