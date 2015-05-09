#ifndef INDIVIDUALS_H
#define INDIVIDUALS_H
#include "FitnessCalculation.h"
#include "../res/BitVector.h"
#include "../res/Constants.h"


#define maxSkill 255

class FitnessCalculation;
class Individuals
{
protected:
    int* _Fitness=0;
    int _ID;
    int _MotherID = -1;
    int _FatherID = -1;

    BitVector* _Genes;
    int cantidadCualidades;
    //FitnessCalculation* FitnessCalc;
    bool veriBase(size_t pNum);

public:
    Individuals();
    Individuals(int pID);
    int getIndividualID();
    void setIndividualID(int pID);
    void setFathers(int pIDFather, int pIDMother);
    int getFathers();


    BitVector *generateCromosoma();
    void createIndividual();
    void setGene(BitVector *pBitVector);
    BitVector* getGenes();
    int getFitness();

    int getCantidadCualidades();

};

#endif // INDIVIDUALS_H
