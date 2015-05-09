#ifndef ELVES_H
#define ELVES_H
#include "../logicGeneticAlgorith/Population.h"
#include "../logicGame/GameIndividual.h"

class Elves : public Population
{
private:
    lista_enlazada<GameIndividual>* _IndividualList;
                                                //Vida,      Inteligencia,      Ataque,     Defensa,       Vel.Ataque,      Magia,
    int _Skills[Constants::SKILLSQUANTITY] = {PrioridadAlta,PrioridadNormal,PrioridadAlta,PrioridadNormal,PrioridadBaja,PrioridadNormal,
                                            //EnergiaVital,   Supersticion, Sacrificio,  Invocacion.
                                              PrioridadNormal,PrioridadAlta,PrioridadBaja,PrioridadAlta};
public:
    Elves(int pSizePopulation, bool pStart);
};

#endif // ELVES_H




