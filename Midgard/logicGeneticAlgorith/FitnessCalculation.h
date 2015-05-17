#ifndef FITNESSCALCULATION_H
#define FITNESSCALCULATION_H

#include "iostream"
#include "Individuals.h"
#include "../res/Constants.h"
#include "../res/BitVector.h"
#include <stdlib.h>

using namespace std;

//class Individuals;
class FitnessCalculation
{
private:
    int _Solution[];

public:            
    static void setSolution(int pSolution[]);

    static int getFitness(BitVector *pIndividualGenes); // ARREGLAR DEPENDENCIA CIRCULAR DE INCLUDES
};

#endif // FITNESSCALCULATION_H
