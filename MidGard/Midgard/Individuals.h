#ifndef INDIVIDUALS_H
#define INDIVIDUALS_H
#include "FitnessCalculation.h"
#include "BitVector.h"
#include "Constants.h"


#define maxSkill 255

class FitnessCalculation;
class Individuals
{
protected:
    int* _Fitness=0;
    int _ID;
    BitVector* _Genes;
    int cantidadCualidades;
    //FitnessCalculation* FitnessCalc;
    bool veriBase(size_t pNum);

public:
    Individuals();
    Individuals(int pID);
    int getIndividualID();
    void setIndividualID(int pID);


    BitVector *generateCromosoma();
    void createIndividual();
    void setGene(BitVector *pBitVector);
    BitVector* getGenes();
    int getFitness();

    int getCantidadCualidades();

};

#endif // INDIVIDUALS_H
