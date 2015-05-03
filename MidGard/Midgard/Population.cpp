#include "Population.h"
int Population::_ID =0;

Population::Population(int pSizePopulation, bool pStart)
{
   // _IndividualList = new lista_enlazada<Individuals>();

     //_PopulationSize = (int*) malloc(sizeof(int));
    _PopulationSize = pSizePopulation;
    _CantidadCualidades = Constants::SKILLSQUANTITY;


    _IndividualList = new lista_enlazada<Individuals>();

    if (pStart)
    {
        for(int i =0; i < _PopulationSize; i++) // Loop para crear los individuos de la poblacion
        {
            Individuals* newIndividual = new Individuals();
            newIndividual->createIndividual();
            insertIndividualList(newIndividual);
            // INGRESAR EL INDIVIDUO A LA LISTA
        }
    }

}


Individuals* Population::getIndividualbyIndex(int pIndex)
{
    return & _IndividualList->getDatabyIndice(pIndex);

}




void Population::insertIndividualList(Individuals* pIndividual)
{

    pIndividual->setIndividualID(_ID);
    _IndividualList->add_Dato_Atras(pIndividual);

    _ID++;

}

int Population::getPopulationSize()
{
    return Constants::MAXPOPULATION;
}

Individuals* Population::getFittest()
{
        //Individuals* fittest = _Individuals[0];

        Individuals* fittest = &_IndividualList->getHead()->getData();


        // Loop through individuals to find fittest
        for (int i = 0; i < (this->_PopulationSize); i++)
        {

            if (fittest->getFitness() <= getIndividualbyIndex(i)->getFitness())
            {
                fittest = getIndividualbyIndex(i);
            }
        }



        return fittest;
    }

int Population::getTotalFitness()
{
    int totalFitness = 0;
    for (int i = 0; i < Constants::MAXPOPULATION; i++) {
        totalFitness += _IndividualList->getDatabyIndice(i).getFitness();
    }
    return totalFitness;

}

