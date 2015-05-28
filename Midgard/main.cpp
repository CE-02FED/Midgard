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
    LogicFacade* w = LogicFacade::getInstance();
    MainLogic* d = new MainLogic();


    w->runLogic(d);

    while(1)
    {

    }
}


    /*srand(time(0));
       randomClass::start();
       DarkElves* myPop = new DarkElves(50, true);
       //Giants* myPop2= new Giants(50, true);

       for(int i=0;i<myPop->getPopulationSize();i++){
           cout<<"Fitness individuo "<< i<<": "<<*(myPop->getIndividualbyIndex(i)->getFitness())<<endl;
       }



       Evolution* evolution = new Evolution();
      // Evolution* evolution2 = new Evolution();

               // Evolve our population until we reach an optimum solution
               int generationCount = 0;
               int * lastFittest;
               //int* lastFittest2;


               while (generationCount <Constants::getInstance()->GENERATIONS)
               {
                   generationCount++;
                   lastFittest=myPop->getFittest()->getFitness();
                   //lastFittest2=myPop2->getFittest()->getFitness();





                   //myPop2 = (Giants*)&(evolution2->evolvePopulation(*myPop2));
                   myPop = (DarkElves*)&(evolution->evolvePopulation(*myPop));
                   if(*(myPop->getFittest()->getFitness())!=*lastFittest){

                  cout << "Generation DarkElves: " << generationCount << " Fittest: " << *(myPop->getFittest()->getFitness()) <<"Tamaño "<<myPop->getPopulationSize()<< endl;
                   }


               }
               cout <<"Solution found!" << endl;

               for(int i=0;i<myPop->getPopulationSize();i++){
                   cout<<"Fitness individuo "<< i<<": "<<*(myPop->getIndividualbyIndex(i)->getFitness())<<" ID: "<< myPop->getIndividualbyIndex(i)->getId()<<endl;
               }

                   cout <<"Generation: " << generationCount << endl;
                   cout <<"Fittest Final DarkElves " <<*(myPop->getFittest()->getFitness())<< endl;
                   cout <<"Fitless Final DarkElves " <<*(myPop->getFitless()->getFitness())<< endl;
}*/
