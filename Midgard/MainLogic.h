#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <iostream>

#include "logicRazas/DarkElves.h"
#include "logicRazas/Elves.h"
#include "logicRazas/Dwarves.h"
#include "logicRazas/Giants.h"
#include "logicGeneticAlgorith/Evolution.h"
#include "logicGame/GameIndividual.h"
#include "res/crazythread.h"
#include "res/vector.h"
#include <unistd.h>

#define darkElves 1
#define elves 2
#define dwarves 3
#define giants 4

#define padre 0;
#define madre 1;
#define IndvFitness 2;


using namespace std;

class MainLogic
{
private:
    static DarkElves* _DarkElvesPopulation;
    static Elves* _ElvesPopulation;
    static Giants* _GiantsPopulation;
    static Dwarves* _DwarvesPopulation;

    static void evolution();

public:    
    MainLogic();
    void runLogic();
    Vector<short> getMap();
    Vector<int> *getParents(int *pRaza, int *pIndividualID);

};

#endif // MAINLOGIC_H
