#include <iostream>
#include "BitVector.h"
#include "Population.h"
#include "Evolution.h"
#include "Giants.h"
#include "DarkElves.h"
#include "Elves.h"
#include "Dwarves.h"






using namespace std;


int main()
{
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

        }






