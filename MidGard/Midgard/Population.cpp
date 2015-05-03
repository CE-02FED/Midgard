#include "Population.h"
int Population::_ID =0;

Population::Population(int pSizePopulation, bool pStart)
{
   // _IndividualList = new lista_enlazada<Individuals>();

     _PopulationSize = (int*) malloc(sizeof(int));
     *_PopulationSize = Constants::MAXPOPULATION;
    _CantidadCualidades = Constants::SKILLSQUANTITY;

    // Inicializa la poblacion
    _Individuals[*_PopulationSize] = (Individuals*)calloc(*_PopulationSize,sizeof(Individuals));

    if (pStart)
    {
        for(int i =0; i < Constants::MAXPOPULATION; i++) // Loop para crear los individuos de la poblacion
        {
            Individuals* newIndividual = new Individuals();
            newIndividual->createIndividual();
            insertIndividualList(newIndividual);
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

void Population::insertIndividualList(Individuals* pIndividual)
{
    //pIndividual->setIndividualID(_ID);
    _Individuals[_ID] = pIndividual;


    //_IndividualList->add_Dato_Atras(pIndividual);

    _ID++;

}

int Population::getPopulationSize()
{
    return Constants::MAXPOPULATION;
}

Individuals Population::getFittest()
{
        Individuals* fittest = _Individuals[0];


        // Loop through individuals to find fittest
        for (int i = 0; i < Constants::MAXPOPULATION; i++) {

            if (fittest->getFitness() <= getIndividualbyIndex(i)->getFitness()) {
                fittest = getIndividualbyIndex(i);                
            }
        }



        return *fittest;
    }

int Population::getTotalFitness()
{
    int totalFitness = 0;
    for (int i = 0; i < Constants::MAXPOPULATION; i++) {
        totalFitness += _Individuals[i]->getFitness();
    }
    return totalFitness;

}

