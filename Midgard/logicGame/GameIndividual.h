#ifndef GAMEINDIVIDUAL_H
#define GAMEINDIVIDUAL_H

#include "../logicGeneticAlgorith/Individuals.h"
#include "../res/lista.h"
#include "../res/randomClass.h"
#include "../logicGame/pathfinding.h"


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
    Pathfinding* _encontrarCamino;

public:
    GameIndividual(int pCualidades[]);
    void createIndividual(int pCualidades[]);
    BitVector* generateCromosoma(int pIndices[]);
    void setFathers(int pIDFather, int pIDMother);
    int getFathers();

    string findPath(Vector<int> pMatrizJuego, int posicionInicialI,int posicionInicialJ,
                    int posicionFinalI,int posicionFinalJ);
};

#endif // GAMEINDIVIDUAL_H
