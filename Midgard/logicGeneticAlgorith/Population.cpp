#include "Population.h"
int Population::_ID =0;
lista<Individuals>* Population::_IndividualList;
Evolution* Population::_Evolution;


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

    _Evolution = new Evolution();

    _IndividualList = new lista<Individuals>();


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
/*
void Population::evolutionThread()
{
    CrazyThread* evolutionThread = new CrazyThread((void*)evolveThis,nullptr);
    evolutionThread->run();
}
*/



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
/*
 void* Population::evolveThis()
{
    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
    int generationCount = 0;
    while(Constants::GENERATIONS)
    {
        pthread_mutex_lock(&mutex);
        generationCount++;
        //_IndividualList = _Evolution->evolvePopulation(*this                                            ).getIndividualList();
        pthread_mutex_unlock(&mutex);
        sleep(1000);
    }
    pthread_exit(NULL);
}
*/
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
    nodo<Individuals>* tmpInd =_IndividualList->getNodo(0);
    for (int i=0; i < (_IndividualList->getNumEle());i++)
    {
        for(int j =0; j< Constants::SKILLSQUANTITY; j++)
        {
            int newSkill = *(tmpInd->getDato()->getGenes()->getByIndex(j) + pSkills[j]);
            if(newSkill>255)
            {
                newSkill = 255;
            }
            tmpInd->getDato()->getGenes()->insertByIndex(j,newSkill);
        }
     }
}





int Population::getTotalFitness()
{
    int totalFitness = 0;
    for (int i = 0; i < *_PopulationSize; i++) {
        totalFitness += *(_IndividualList->getElemento(i)->getFitness());
    }
    return totalFitness;

}

void Population::isPopBirthDay()
{
    nodo<Individuals>* tmpIndividual = _IndividualList->getNodo(0);
    for(int i =0; i< _IndividualList->getNumEle();i++)
    {
        tmpIndividual->getDato()->isMyBirthDay();
        tmpIndividual = tmpIndividual->getSiguiente();
    }

}

