#include "MainLogic.h"

DarkElves* MainLogic::_DarkElvesPopulation;
Elves* MainLogic::_ElvesPopulation;
Giants* MainLogic::_GiantsPopulation;
Dwarves* MainLogic::_DwarvesPopulation;

MainLogic::MainLogic()
{
}

Vector<int>* MainLogic::getParents(int* pRaza, int* pIndividualID)
{
    Vector<int>* Family = new Vector<int>(3);
    switch (*pRaza) {
    case darkElves:
        Family[0] = _DarkElvesPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _DarkElvesPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _DarkElvesPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;

    case elves:
        Family[0] = _ElvesPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _ElvesPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _ElvesPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;

    case dwarves:
        Family[0] = _DwarvesPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _DwarvesPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _DwarvesPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;
    case giants:
        Family[0] = _GiantsPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _GiantsPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _GiantsPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;
    default:
        break;
    }
    return Family;
}

Vector<short> MainLogic::getMap()
{

}



void MainLogic::runLogic()
{
    CrazyThread* runThread = new CrazyThread((void*)evolution, nullptr);
    runThread->run();

    while(1)
    {

    }

}

void MainLogic::evolution()
{
    srand(time(0));
    _DarkElvesPopulation = new DarkElves(50, true);
    _GiantsPopulation = new Giants(50, true);
    _DwarvesPopulation = new Dwarves(50, true);
    _ElvesPopulation = new Elves(50, true);

    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
    Evolution* evolution = new Evolution();

    // Evolve our population until we reach an optimum solution
    int generationCount = 0;
    while (generationCount <300)
    {
        pthread_mutex_lock(&mutex);
        generationCount++;
        _DarkElvesPopulation = &evolution->evolvePopulation(*_DarkElvesPopulation);
        _GiantsPopulation = &evolution->evolvePopulation(*_GiantsPopulation);
        _DwarvesPopulation = &evolution->evolvePopulation(*_DwarvesPopulation);
        _ElvesPopulation = &evolution->evolvePopulation(*_ElvesPopulation);
        pthread_mutex_unlock(&mutex);
        usleep(1000);
    }

}
