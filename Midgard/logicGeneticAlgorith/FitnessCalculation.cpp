#include "FitnessCalculation.h"

FitnessCalculation::FitnessCalculation(){}

int FitnessCalculation::getFitness(BitVector* pIndividualGenes) // VERIFICAR BIEN
{

    int tmpFitness =0;

    for(size_t i=0; i< Constants::SKILLSQUANTITY; i++)
    {

        unsigned char skillValue = (pIndividualGenes->getByIndex(i));

        tmpFitness+= skillValue;


    }
    return tmpFitness;
}
