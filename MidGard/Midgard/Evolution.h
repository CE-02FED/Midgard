#ifndef EVOLUTION_H
#define EVOLUTION_H

#include "Individuals.h"
#include "Population.h"
#include "random"
#include "Constants.h"

#define Mask 00000000


class Evolution
{
private:
    double _mutationRate = 0.1;
    double _uniformRate = 0.5;
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
