#ifndef RANDOM_H
#define RANDOM_H

#include "randomClass.h"

class Random
{
public:
    Random();
    int randRange(int pMin, int pMax);
    double randRange(double pMin, double pMax);
    int getRandom(int pLimit);
    void start();

};

#endif // RANDOM_H
