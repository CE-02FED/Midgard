#ifndef POPULATION_H
#define POPULATION_H

#include "../res/Constants.h"
#include "Individuals.h"
#include "../res/lista.h"
#include "../logicGeneticAlgorith/Evolution.h"

#include <unistd.h>
#include "../res/crazythread.h"
#include <iostream>
#include "../res/vector.h"


class Evolution;
class Population
{
protected:
    Individuals* _Individuals[];
    int _CantidadCualidades;
    int* _PopulationSize=0;
    //std::unordered_map <int,Individuals>* _IndividualList;
    static lista<Individuals>* _IndividualList;


public:

    static Evolution* _Evolution;
    Population();
    Individuals* getFitless();
    void deleteIndividualList(Individuals* pIndividual);
    Population(int pSizePopulation, bool pStart);
    void upPopulation();
    void downPopulation();
    Individuals *getIndividualbyIndex(int pIndex);

    lista<Individuals>* getIndividualList();
    void insertIndividualList(Individuals *pIndividual);
    int getPopulationSize();
    Individuals* getFittest();
    int getTotalFitness();

    static void *evolveThis();
    void evolutionThread();

    void isPopBirthDay();

    void CambioEdda(Vector<int> pSkills);

    static int _ID;
};

#endif // POPULATION_H
