#ifndef FITNESSCALCULATION_H
#define FITNESSCALCULATION_H

#include "ios"
#include "Individuals.h"
#include "Constants.h"
#include "BitVector.h"

class Individuals;
class FitnessCalculation
{
private:
    int _Solution[];

public:
    FitnessCalculation();
    static int BnToDec(size_t pNum);
    static bool veriBase(size_t pNum);
    static void setSolution(int pSolution[]);

    static int getFitness(Individuals *pIndividual); // ARREGLAR DEPENDENCIA CIRCULAR DE INCLUDES
};

#endif // FITNESSCALCULATION_H
