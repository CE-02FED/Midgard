#ifndef JSONREADER_H
#define JSONREADER_H

#include "../libs/rapidjson/rapidjson.h"
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/stringbuffer.h"
#include "../libs/rapidjson/writer.h"
#include "../res/vector.h"
#include "../res/Constants.h"

class jsonReader
{
public:
    //Gui
    Vector<int> *readMap(string pJson);
    Vector<int>* readFamily(string pJson);
    Vector<int>* readFight(string pJson);
    int readType(string pJson);

    //Logic
    Vector<int>* readFamilyFromGUI(string pJson);

};

#endif // JSONREADER_H
