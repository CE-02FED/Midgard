#include <iostream>
#include "res/BitVector.h"
//#include "logicGeneticAlgorith/Population.h"
#include "logicGeneticAlgorith/Evolution.h"
#include "logicRazas/Giants.h"
#include "logicRazas/DarkElves.h"
#include "logicRazas/Elves.h"
#include "logicRazas/Dwarves.h"
#include "DataAccess/socketserver.h"





using namespace std;


int main()
{
 SocketServer* d = new SocketServer();
}
    /*
    srand(time(0));
    DarkElves* myPop = new DarkElves(50, true);



    Evolution* evolution = new Evolution();

            // Evolve our population until we reach an optimum solution
            int generationCount = 0;
            while (generationCount <30)
            {
                generationCount++;

                cout << "Generation: " << generationCount << " Fittest: " << (myPop->getFittest()->getFitness()) << endl;



                myPop = &evolution->evolvePopulation(*myPop);

            }
            cout <<"Solution found!" << endl;
            cout <<"Generation: " << generationCount << endl;
            cout << myPop->getFittest()->getFitness()<< endl;

        }*/






