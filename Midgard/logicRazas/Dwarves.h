#ifndef DWARVES_H
#define DWARVES_H

#include "../logicGeneticAlgorith/Population.h"
#include "../logicGame/GameIndividual.h"

class Dwarves:public Population
{
private:
    lista_enlazada<GameIndividual>* _IndividualList;
                                                //Vida,      Inteligencia,      Ataque,     Defensa,       Vel.Ataque,      Magia,
    int _Skills[Constants::SKILLSQUANTITY] = {PrioridadAlta,PrioridadNormal,PrioridadAlta,PrioridadNormal,PrioridadBaja,PrioridadNormal,
                                            //EnergiaVital,   Supersticion, Sacrificio,  Invocacion.
                                              PrioridadNormal,PrioridadAlta,PrioridadBaja,PrioridadAlta};
public:
    Dwarves(int pSizePopulation, bool pStart);
};
#endif // DWARVES_H
