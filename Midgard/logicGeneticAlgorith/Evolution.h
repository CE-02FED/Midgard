#ifndef EVOLUTION_H
#define EVOLUTION_H

#include "Individuals.h"
#include "Population.h"
#include "../res/randomClass.h"
#include "../res/Constants.h"

#define Mask 1
#define partesDelaPoblacion 2
#define mutationLowLimit 0.0
#define mutationHightLimit 10.5


class Evolution
{
private:
    double _mutationRate = 2.0;
    double _uniformRate = 0.9;
    bool _PreserveTheBest = true; // Mantiene al mejor individuo
    int _PoolFathersSize = 10; // Cantidad de miembros de un grupo para seleccionar los padres





    Individuals fathersSelection(Population pPopulation); // Forma un pequeño grupo de individuos y de ahi saca el mas apto
    void Mutation(Individuals *pIndividual); // Muta el gen
    Individuals* CrossOver(Individuals pFatherA, Individuals pFatherB); // Hace el cruce entre 2 individuos

public:
    Evolution();
     Population evolvePopulation(Population pPopulation);
};

#endif // EVOLUTION_H