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

#define cero 0
#define primerElemento 0

class Individuals;
class Map;
class Evolution;
class Population
{
protected:
    Individuals* _Individuals[];
    int _CantidadCualidades;
    int* _PopulationSize=cero;
    //std::unordered_map <int,Individuals>* _IndividualList;
    static lista<Individuals>* _IndividualList;


public:

    static Evolution* _Evolution;
    Population();
    Individuals* getFitless();
    bool deleteIndividualList(Individuals* pIndividual);
    Population(int pSizePopulation);
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
