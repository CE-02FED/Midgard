#include "randomClass.h"

double randomClass::randRange(double pMin, double pMax)
{
    return ((double) rand() / (((double)RAND_MAX+1.0) * (pMax-pMin+1) + pMin));
}
int  randomClass::randRange(int pMin, int pMax)
{
    return pMin+(rand()%(int)(pMax-pMin +1));
}
int randomClass::getRandom(int pLimit)
{
    return rand()%pLimit;
}
void randomClass::start()
{
    srand(time(0));
}
