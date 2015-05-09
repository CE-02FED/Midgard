#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <iostream>

#include "DarkElves.h"
#include "Elves.h"
#include "Dwarves.h"
#include "Giants.h"
#include "Evolution.h"
#include "crazythread.h"


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
