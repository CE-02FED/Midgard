#include "Population.h"
int Population::_ID =0;
Population::Population(){

}

Population::Population(int pSizePopulation, bool pStart)
{
    //std::cout<<"Crea una poblacion de tamaño "<<pSizePopulation<<std::endl;
   // _IndividualList = new lista_enlazada<Individuals>();

     _PopulationSize = (int*) malloc(sizeof(int));
    //Population* pPopulation= new Population();
    *_PopulationSize = pSizePopulation;
    _CantidadCualidades = Constants::SKILLSQUANTITY;


    _IndividualList = new lista<Individuals>();
    this = 3;

    if (false)
    {
        for(int i =0; i < *_PopulationSize; i++) // Loop para crear los individuos de la poblacion
        {
            Individuals* newIndividual = new Individuals();
            std::cout<<"fitness individuo nuevo "<<*(newIndividual->getFitness())<<std::endl;
            newIndividual->createIndividual();
            insertIndividualList(newIndividual);
            // INGRESAR EL INDIVIDUO A LA LISTA
        }

    }
    //std::cout<<"#Ele lista "<<_IndividualList->getNumEle()<<std::endl;

}


Individuals* Population::getIndividualbyIndex(int pIndex)
{
    return  _IndividualList->getElemento(pIndex);

}
void Population::upPopulation(){
    (*(_PopulationSize))++;
}

void Population::downPopulation(){
    (*(_PopulationSize))--;
}


void Population::insertIndividualList(Individuals* pIndividual)
{

    pIndividual->setIndividualID(_ID);
    _IndividualList->agregarFinal(pIndividual);
    //std::cout<<"Se agrega al final de la lista "<<*(pIndividual->getFitness())<<std::endl;
    _ID++;

}
void Population::deleteIndividualList(Individuals* pIndividual){

  int id= pIndividual->getId();
  for(int i=0;i<_IndividualList->getNumEle();i++){
      if(id==_IndividualList->getElemento(i)->getId()){
          _IndividualList->eliminar(i);
      }
  }
}

int Population::getPopulationSize()
{
    return *_PopulationSize;
}

Individuals* Population::getFittest()
{
        nodo<Individuals>* tmpNodo = _IndividualList->getNodo(0);
        Individuals* fittest = tmpNodo->getDato();
        //std::cout<<"Tamaño Lista "<<_IndividualList->getNumEle()<<std::endl;
        //std::cout<<"Cantidad de Individuos "<<*_PopulationSize<<std::endl;

        // Loop through individuals to find fittest
        for (int i = 0; i < (*(this->_PopulationSize)); i++)
        {
            //std::cout<<"Fitness en Nodo "<<*(tmpNodo->getDato()->getFitness())<<std::endl;

            if (*(fittest->getFitness()) <= *(tmpNodo->getDato()->getFitness()))
            {
                fittest = tmpNodo->getDato();
            }
            tmpNodo = tmpNodo->getSiguiente();
        }
        return fittest;
    }
Individuals* Population::getFitless()
{
        nodo<Individuals>* tmpNodo = _IndividualList->getNodo(0);
        Individuals* fitless = tmpNodo->getDato();
        //std::cout<<"Tamaño Lista "<<_IndividualList->getNumEle()<<std::endl;
        //std::cout<<"Cantidad de Individuos "<<*_PopulationSize<<std::endl;

        // Loop through individuals to find fittest
        for (int i = 0; i < (*(this->_PopulationSize)); i++)
        {
            //std::cout<<"Fitness en Nodo "<<*(tmpNodo->getDato()->getFitness())<<std::endl;

            if (*(fitless->getFitness()) >= *(tmpNodo->getDato()->getFitness()))
            {
                fitless = tmpNodo->getDato();
            }
            tmpNodo = tmpNodo->getSiguiente();
        }
        return fitless;
    }

int Population::getTotalFitness()
{
    int totalFitness = 0;
    for (int i = 0; i < *_PopulationSize; i++) {
        totalFitness += *(_IndividualList->getElemento(i)->getFitness());
    }
    return totalFitness;

}

