#include "MainLogic.h"

MainLogic::MainLogic()
{
}

string MainLogic::getParents(string clase, string pID)
{

}

Vector<short> MainLogic::getMap()
{

}

void MainLogic::runLogic()
{
     srand(time(0));
     darkElvesPopulation = new DarkElves(50, true);

     Evolution* evolution = new Evolution();

             // Evolve our population until we reach an optimum solution
             int generationCount = 0;
             while (generationCount <300)
             {
                 generationCount++;

                 cout << "Generation: " << generationCount << " Fittest: " << (darkElvesPopulation->getFittest()->getFitness()) << endl;



                 darkElvesPopulation = &evolution->evolvePopulation(*darkElvesPopulation);

             }
             cout <<"Solution found!" << endl;
             cout <<"Generation: " << generationCount << endl;
             cout << darkElvesPopulation->getFittest()->getFitness()<< endl;

}
