#include "DarkElves.h"

DarkElves::DarkElves(int pSizePopulation, bool pStart) : Population(pSizePopulation,pStart)
{
    //Population::Population(pSizePopulation,false);
    _PopulationSize = (int*) malloc(sizeof(int));
    *_PopulationSize = Constants::getInstance()->MAXPOPULATION;
   _CantidadCualidades = Constants::SKILLSQUANTITY;

   // Inicializa la poblacion
   //_Individuals [*_PopulationSize] = (Individuals*)calloc(*_PopulationSize,sizeof(Individuals));

   _IndividualList = new lista<GameIndividual>();

   if (pStart)
   {
       for(int i =0; i < Constants::getInstance()->MAXPOPULATION; i++) // Loop para crear los individuos de la poblacion
       {

           GameIndividual* newIndividual = new GameIndividual(_Skills);

           insertIndividualList(newIndividual);
       }
   }
}


