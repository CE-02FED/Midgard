#ifndef DARKELVES_H
#define DARKELVES_H
#include "../logicGeneticAlgorith/Population.h"
#include "../logicGame/GameIndividual.h"

class DarkElves : public Population
{
private:
    lista_enlazada<GameIndividual>* _IndividualList;
                                                //Vida,      Inteligencia,      Ataque,     Defensa,       Vel.Ataque,      Magia,
    int _Skills[Constants::SKILLSQUANTITY] = {PrioridadAlta,PrioridadNormal,PrioridadAlta,PrioridadNormal,PrioridadBaja,PrioridadNormal,
                                            //EnergiaVital,   Supersticion, Sacrificio,  Invocacion.
                                              PrioridadNormal,PrioridadAlta,PrioridadBaja,PrioridadAlta};
public:
    DarkElves(int pSizePopulation, bool pStart);
};

#endif // DARKELVES_H
