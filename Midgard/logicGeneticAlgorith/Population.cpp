#include "Population.h"
int Population::_ID =0;

Population::Population(int pSizePopulation, bool pStart)
{
    std::cout<<"Crea una poblacion de tamaño "<<pSizePopulation<<std::endl;
   // _IndividualList = new lista_enlazada<Individuals>();

     //_PopulationSize = (int*) malloc(sizeof(int));
    _PopulationSize = pSizePopulation;
    _CantidadCualidades = Constants::SKILLSQUANTITY;


    _IndividualList = new lista<Individuals>();


    if (pStart)
    {
        for(int i =0; i < _PopulationSize; i++) // Loop para crear los individuos de la poblacion
        {
            Individuals* newIndividual = new Individuals();
            std::cout<<"fitness individuo nuevo "<<*(newIndividual->getFitness())<<std::endl;
            newIndividual->createIndividual();
            insertIndividualList(newIndividual);
            // INGRESAR EL INDIVIDUO A LA LISTA
        }

    }
    std::cout<<"#Ele lista "<<_IndividualList->getNumEle()<<std::endl;

}


Individuals* Population::getIndividualbyIndex(int pIndex)
{
    return  _IndividualList->getElemento(pIndex);

}




void Population::insertIndividualList(Individuals* pIndividual)
{

    pIndividual->setIndividualID(_ID);
    _IndividualList->agregarFinal(pIndividual);

    _ID++;

}

int Population::getPopulationSize()
{
    return _PopulationSize;
}

Individuals* Population::getFittest()
{
        nodo<Individuals>* tmpNodo = _IndividualList->getNodo(0);
        Individuals* fittest = tmpNodo->getDato();
        std::cout<<"Tamaño Lista "<<_IndividualList->getNumEle()<<std::endl;
        std::cout<<"Cantidad de Individuos "<<_PopulationSize<<std::endl;

        // Loop through individuals to find fittest
        for (int i = 0; i < (this->_PopulationSize); i++)
        {
            std::cout<<*(tmpNodo->getDato()->getFitness())<<std::endl;

            if (*(fittest->getFitness()) <= *(tmpNodo->getDato()->getFitness()))
            {
                fittest = tmpNodo->getDato();
            }
            tmpNodo = tmpNodo->getSiguiente();
        }
        return fittest;
    }

int Population::getTotalFitness()
{
    int totalFitness = 0;
    for (int i = 0; i < _PopulationSize; i++) {
        totalFitness += _IndividualList->getElemento(i)->getFitness();
    }
    return totalFitness;

}

