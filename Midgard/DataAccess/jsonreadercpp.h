#ifndef JSONREADERCPP_H
#define JSONREADERCPP_H
#include <json/json.h>
#include <iostream>
#include "res/vector.h"
using namespace std;
class jsonReaderCpp
{
public:
    //Gui
    Vector<int>* readMap (string pJson);
    int readType (string pJson);
    Vector<int> *readFamily(string pJson);
    Vector<int>* readFight (string pJson);

    //Logic
    Vector<int>* readFamilyFromGUI(string pJson);

};

#endif // JSONREADERCPP_H
