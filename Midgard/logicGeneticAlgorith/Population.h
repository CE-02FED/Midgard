#ifndef POPULATION_H
#define POPULATION_H

#include "../res/Constants.h"
#include "Individuals.h"
#include "../res/lista.h"

#include <iostream>




class Population
{
protected:
    Individuals* _Individuals[];
    int _CantidadCualidades;
    int* _PopulationSize=0;
    //std::unordered_map <int,Individuals>* _IndividualList;
    lista<Individuals>* _IndividualList;


public:
    Population();
    Population(int pSizePopulation, bool pStart);
    void upPopulation();
    Individuals *getIndividualbyIndex(int pIndex);

    Individuals *getIndividualList(int pIndex);
    void insertIndividualList(Individuals *pIndividual);
    int getPopulationSize();
    Individuals* getFittest();
    int getTotalFitness();

    static int _ID;
};

#endif // POPULATION_H
