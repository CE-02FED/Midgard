#include "FitnessCalculation.h"

FitnessCalculation::FitnessCalculation(){}

int FitnessCalculation::getFitness(Individuals* pIndividual) // VERIFICAR BIEN
{

    int tmpFitness =0;

    for(size_t i=0; i< Constants::SKILLSQUANTITY; i++)
    {
        BitVector* d = pIndividual->getGenes();

        cout << "fitness calculation" << endl;
        size_t numeroBinario = pIndividual->getGenes()->getByIndex(i);

        int skillValue = BnToDec(numeroBinario);

        tmpFitness+= skillValue;

    }
    return tmpFitness;
}


// Establecer funcion que devuelva la solucion optima, la cual se usara para terminar el while del Algoritmo Genetico


int FitnessCalculation::BnToDec(size_t pNum)
{
    if(!veriBase(pNum))
    {
        cout << "No es un numero binario" <<endl;
        exit (EXIT_FAILURE);
    }

    int exp=0;
    int result=0;

    while (pNum!=0)
    {
        result+= pNum%10 * (pow (2, exp));
        pNum= pNum/10;
        exp+=1;
    }
     return result;
}

bool FitnessCalculation::veriBase(size_t pNum)
{
    while(pNum!=0)
    {
        if(pNum%10<2)
            pNum=pNum/10;
        else
            return false;
    }
    return true;
}
