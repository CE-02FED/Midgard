#include "Population.h"
int Population::_ID =cero;
lista<Individuals>* Population::_IndividualList;
Evolution* Population::_Evolution;


Population::Population(){

}

Population::Population(int pSizePopulation)
{


     _PopulationSize = (int*) malloc(sizeof(int));
    *_PopulationSize = pSizePopulation;
    _CantidadCualidades = Constants::SKILLSQUANTITY;

    _Evolution = new Evolution();

    _IndividualList = new lista<Individuals>();



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

    //pIndividual->setIndividualID(_ID);
    _IndividualList->agregarFinal(pIndividual);
    //_ID++;

}
bool Population::deleteIndividualList(Individuals* pIndividual){

  int id= pIndividual->getId();
  //std::cout<<"Id IND"<<id<<std::endl;
  for(int i=cero;i<_IndividualList->getNumEle();i++){
      if(id==_IndividualList->getElemento(i)->getId()){
          //std::cout<<"Elimino Id IND"<<_IndividualList->getElemento(i)->getId()<<std::endl;
          _IndividualList->eliminar(i);
          return true;

      }
  }
  return false;
}

int Population::getPopulationSize()
{
    return *_PopulationSize;
}

Individuals* Population::getFittest()
{
        nodo<Individuals>* tmpNodo = _IndividualList->getNodo(primerElemento);
        Individuals* fittest = tmpNodo->getDato();

        // Loop through individuals to find fittest
        for (int i = cero; i < (*(this->_PopulationSize)); i++)
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
        nodo<Individuals>* tmpNodo = _IndividualList->getNodo(primerElemento);
        Individuals* fitless = tmpNodo->getDato();

        // Loop through individuals to find fittest
        for (int i = cero; i < (*(this->_PopulationSize)); i++)
        {

            if (*(fitless->getFitness()) >= *(tmpNodo->getDato()->getFitness()))
            {
                fitless = tmpNodo->getDato();
            }
            tmpNodo = tmpNodo->getSiguiente();
        }
        return fitless;
    }

lista<Individuals>* Population::getIndividualList()
{
    return this->_IndividualList;
}

/** La casilla Indice =0 del array representará la Vida
* La casilla Indice =1 del array representará la Inteligencia
* La casilla Indice =2 del array representará el Ataque
* La casilla Indice =3 del array representará la Defensa
* La casilla Indice =4 del array representará la Velocidad de ataque
* La casilla Indice =5 del array representará la Magia
* La casilla Indice =6 del array representará la Energia Vital
* La casilla Indice =7 del array representará la Supersticion
* La casilla Indice =8 del array representará el Sacrificio
* La casilla Indice =9 del array representará la Invocacion
* */
void Population::CambioEdda(Vector<int> pSkills)
{
    nodo<Individuals>* tmpInd =_IndividualList->getNodo(primerElemento);
    for (int i=cero; i < (_IndividualList->getNumEle());i++)
    {
        for(int j =cero; j< Constants::SKILLSQUANTITY; j++)
        {
            int newSkill = *(tmpInd->getDato()->getGenes()->getByIndex(j) + pSkills[j]);
            if(newSkill>Constants::MAXSKILL)
            {
                newSkill = Constants::MAXSKILL;
            }
            tmpInd->getDato()->getGenes()->insertByIndex(j,newSkill);
        }
     }
}





int Population::getTotalFitness()
{
    int totalFitness = cero;
    for (int i = cero; i < *_PopulationSize; i++) {
        totalFitness += *(_IndividualList->getElemento(i)->getFitness());
    }
    return totalFitness;

}

void Population::isPopBirthDay()
{
    nodo<Individuals>* tmpIndividual = _IndividualList->getNodo(primerElemento);
    for(int i =cero; i< _IndividualList->getNumEle();i++)
    {
        tmpIndividual->getDato()->isMyBirthDay();
        tmpIndividual = tmpIndividual->getSiguiente();
    }
}

