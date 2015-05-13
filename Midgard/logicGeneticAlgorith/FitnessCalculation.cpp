#include "FitnessCalculation.h"


int FitnessCalculation::getFitness(BitVector* pIndividualGenes) // VERIFICAR BIEN
{

    int tmpFitness =0;

    for(int i=0; i< Constants::SKILLSQUANTITY; i++)
    {
        cout << "habiilidad: " << to_string(pIndividualGenes->getByIndex(i)) << endl;
        u_int8_t skillValue = (pIndividualGenes->getByIndex(i));

        tmpFitness+= skillValue;
    }   
    return tmpFitness;
}
