#include <iostream>
#include "BitVector.h"
#include "Population.h"
#include "Evolution.h"
#include "Giants.h"
#include "DarkElves.h"
#include "Elves.h"
#include "Dwarves.h"
#include "socketserver.h"





using namespace std;


int main()
{

    SocketServer* d = new SocketServer();


     while(true)
     {
         cout<<"hola"<< endl;
     };



}
   /* srand(time(0));
    DarkElves* myPop = new DarkElves(50, true);



    Evolution* evolution = new Evolution();

            // Evolve our population until we reach an optimum solution
            int generationCount = 0;
            while (generationCount <300)
            {
                generationCount++;

                cout << "Generation: " << generationCount << " Fittest: " << (myPop->getFittest()->getFitness()) << endl;



                myPop = &evolution->evolvePopulation(*myPop);

            }
            cout <<"Solution found!" << endl;
            cout <<"Generation: " << generationCount << endl;
            cout << myPop->getFittest()->getFitness()<< endl;

        }
*/





