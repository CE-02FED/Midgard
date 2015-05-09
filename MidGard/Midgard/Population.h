#ifndef POPULATION_H
#define POPULATION_H

#include "Constants.h"
#include "Individuals.h"
#include "lista_enlazada.h"

#include <iostream>




class Population
{
protected:
    Individuals* _Individuals[];
    int _CantidadCualidades;
    int _PopulationSize;
    //std::unordered_map <int,Individuals>* _IndividualList;
    lista_enlazada<Individuals>* _IndividualList;


public:
    Population(int pSizePopulation, bool pStart);

    Individuals *getIndividualbyIndex(int pIndex);

    Individuals *getIndividualList(int pIndex);
    void insertIndividualList(Individuals *pIndividual);
    int getPopulationSize();
    Individuals *getFittest();
    int getTotalFitness();

    static int _ID;
};

#endif // POPULATION_H
