#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <iostream>

#include "logicRazas/DarkElves.h"
#include "logicRazas/Elves.h"
#include "logicRazas/Dwarves.h"
#include "logicRazas/Giants.h"
#include "logicGeneticAlgorith/Evolution.h"
#include "res/crazythread.h"


using namespace std;

class MainLogic
{
private:
    DarkElves* darkElvesPopulation;

public:    
    MainLogic();
    void runLogic();
    string getMap();
    string getParents(string clase, string pID);

};

#endif // MAINLOGIC_H
