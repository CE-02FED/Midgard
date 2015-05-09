#ifndef GIANTS_H
#define GIANTS_H
#include "../logicGeneticAlgorith/Population.h"
#include "../logicGame/GameIndividual.h"

class Giants : public Population
{
private:
    lista_enlazada<GameIndividual>* _IndividualList;
                                                //Vida,      Inteligencia,      Ataque,     Defensa,       Vel.Ataque,      Magia,
    int _Skills[Constants::SKILLSQUANTITY] = {PrioridadAlta,PrioridadNormal,PrioridadAlta,PrioridadNormal,PrioridadBaja,PrioridadNormal,
                                            //EnergiaVital,   Supersticion, Sacrificio,  Invocacion.
                                              PrioridadNormal,PrioridadAlta,PrioridadBaja,PrioridadAlta};
public:
    Giants (int pSizePopulation, bool pStart);
};

#endif // GIANTS_H
