#include "Population.h"
int Population::_ID =0;

Population::Population(int pSizePopulation, bool pStart)
{
    _IndividualList = new lista_enlazada<Individuals>();

     _PopulationSize = pSizePopulation;

    _CantidadCualidades = Constants::_SkillsQuantity;

    // Inicializa la poblacion
    _Individuals [_PopulationSize] = new Individuals();



    if (pStart)
    {
        for(int i =0; i < _PopulationSize; i++) // Loop para crear los individuos de la poblacion
        {
            Individuals* newIndividual = new Individuals();
            newIndividual->createIndividual();
            insertIndividualList(*newIndividual);            
            // INGRESAR EL INDIVIDUO AL ARRAY O A LA LISTA
        }
    }
}


Individuals* Population::getIndividualbyIndex(int pIndex)
{
    return _Individuals[pIndex];
}


Individuals* Population::getIndividualList(int pIndex)
{
    //Individuals tmp = _IndividualList[pIndex];

}

void Population::insertIndividualList(Individuals pIndividual)
{

    _IndividualList->add_Dato_Atras(pIndividual);


    _ID++;

}

int Population::getPopulationSize()
{
    return this->_PopulationSize;
}

Individuals Population::getFittest()
{
        Individuals* fittest = _Individuals[0];
        // Loop through individuals to find fittest
        for (int i = 0; i < _PopulationSize; i++) {

            if (fittest->getFitness() <= getIndividualbyIndex(i)->getFitness()) {
                fittest = getIndividualbyIndex(i);                

            }

        }


        return *fittest;
    }

int Population::getTotalFitness()
{
    int totalFitness =0;
    for (int i = 0; i < _PopulationSize; i++) {
        totalFitness += _Individuals[i]->getFitness();
    }
    return totalFitness;

}

