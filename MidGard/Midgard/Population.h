#ifndef POPULATION_H
#define POPULATION_H

#include "Constants.h"
#include "Individuals.h"

#include <iostream>




class Population
{
private:
    Individuals* _Individuals[];
    int _CantidadCualidades;
    int* _PopulationSize=0;
    //std::unordered_map <int,Individuals>* _IndividualList;
    //lista_enlazada<Individuals>* _IndividualList;


public:
    Population(int pSizePopulation, bool pStart);

    Individuals *getIndividualbyIndex(int pIndex);

    Individuals *getIndividualList(int pIndex);
    void insertIndividualList(Individuals *pIndividual);
    int getPopulationSize();
    Individuals getFittest();
    int getTotalFitness();

    static int _ID;
};

#endif // POPULATION_H
