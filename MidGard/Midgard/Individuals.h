#ifndef INDIVIDUALS_H
#define INDIVIDUALS_H
#include "FitnessCalculation.h"
#include "BitVector.h"
#include "Constants.h"
#include "math.h"

class FitnessCalculation;
class Individuals
{
private:
    int _Fitness=0;
    int _ID;
    BitVector* genes;
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

    size_t DecToBn(int pNum, int exp);
    int BnToDec(unsigned long pNum);

    int getFitness();

};

#endif // INDIVIDUALS_H
