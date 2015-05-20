#ifndef JSONWRITERCPP_H
#define JSONWRITERCPP_H
#include <iostream>
#include"res/vector.h"


using namespace std;

class jsonWriterCpp
{
public:
    //Logic

    string writeMap(Vector<int> pMatriz);
    string writeFamily(int pFather, int pMother, int pFitness);
    string writeFight(int pPopulation1, int pPopulation2);

    //GUI
    string writeFamilyFromGUI(int pRaza, int pIndividuoID);
    string writeType(int pType);
};

#endif // JSONWRITERCPP_H
