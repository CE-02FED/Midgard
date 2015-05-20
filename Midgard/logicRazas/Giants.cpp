#include "Giants.h"

Giants::Giants(int pSizePopulation, bool pStart) : Population(pSizePopulation,pStart)
{
    _PopulationSize = pSizePopulation;

   _CantidadCualidades = Constants::SKILLSQUANTITY;

   // Inicializa la poblacion
   //_Individuals [*_PopulationSize] = (Individuals*)calloc(*_PopulationSize,sizeof(Individuals));

   _IndividualList = new lista<GameIndividual>();

   if (pStart)
   {
       for(int i =0; i < this->_PopulationSize; i++) // Loop para crear los individuos de la poblacion
       {

           GameIndividual* newIndividual = new GameIndividual(_Skills);
           insertIndividualList(newIndividual);
       }
   }
       std::cout <<" psize" <<_PopulationSize <<std::endl;
}


