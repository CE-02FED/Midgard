#include "Random.h"


Random::Random()
{
    start();
}

int Random::randRange(int pMin, int pMax)
{
    return randomClass::randRange(pMin,pMax);
}

double Random::randRange(double pMin, double pMax)
{
    return randomClass::randRange(pMin,pMax);

}

int Random::getRandom(int pLimit)
{
    return randomClass::getRandom(pLimit);
}

void Random::start()
{
    srand(time(0));
}
