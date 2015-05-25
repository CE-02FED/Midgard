#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <iostream>

#include "logicRazas/DarkElves.h"
#include "logicRazas/Elves.h"
#include "logicRazas/Dwarves.h"
#include "logicRazas/Giants.h"
#include "logicGeneticAlgorith/Evolution.h"
#include "logicGame/GameIndividual.h"
#include "res/crazythread.h"
#include "res/vector.h"
#include "DataAccess/docXML.h"
#include <unistd.h>

#define darkElves 1
#define elves 2
#define dwarves 3
#define giants 4

#define padre 0;
#define madre 1;
#define IndvFitness 2;

#define EddaAntigua 0
#define EddaReligiosa 1
#define EddaCienciaTecnologia 2
#define EddaSupremacia 3
#define EddaPazMundial 4
#define AtardecerDioses 5
#define CantPoblaciones 4

#define despreciable -40
#define noCambia 0
#define alto 15

#define vida 0
#define inteligencia 1
#define ataque 2
#define defensa 3
#define velAtaque 4
#define magia 5
#define energiaVital 6
#define supersticion 7
#define sacrificio 8
#define invocacion 9

using namespace std;

class MainLogic
{
private:
    static DarkElves* _DarkElvesPopulation;
    static Elves* _ElvesPopulation;
    static Giants* _GiantsPopulation;
    static Dwarves* _DwarvesPopulation;
    static Evolution* _Evolution;
    docXML* archivoXML;
    Vector<int>* matriz;

    static void evolution();
    Vector<int> *initMatriz();

    static bool EddaAntiguaMethod(bool pImprovePopulation);
    static bool EddaReligiosaMethod(bool pImprovePopulation);
    static bool EddaCienciaTecnologiaMethod(bool pImprovePopulation);
    static bool EddaSupremaciaMethod(bool pImprovePopulation);
    static void EddaPazMundialMethod();

    static int Age;
    static int EddaActual;

public:
    MainLogic();
    void runLogic();
    Vector<int> *getMap();
    Vector<int> *getParents(int *pRaza, int *pIndividualID);

    static void HappyNewYear();
    static void mainGame();
    void indidvidualFight();
};

#endif // MAINLOGIC_H
