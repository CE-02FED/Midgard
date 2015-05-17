#ifndef GAMEINDIVIDUAL_H
#define GAMEINDIVIDUAL_H

#include "../logicGeneticAlgorith/Individuals.h"
#include "../res/lista.h"
#include "../res/randomClass.h"


#define PrioridadAlta 1
#define PrioridadBaja -1
#define MidValue 125
#define lowestValue 0
#define PrioridadNormal 0

class GameIndividual : public Individuals
{
private:
    int _MotherID = -1;
    int _FatherID = -1;
    int _Age =0;
public:
    GameIndividual(int pCualidades[]);
    void createIndividual(int pCualidades[]);
    BitVector* generateCromosoma(int pIndices[]);
    void setFathers(int pIDFather, int pIDMother);
    int getFathers();
    void BirthDay();
};

#endif // GAMEINDIVIDUAL_H
