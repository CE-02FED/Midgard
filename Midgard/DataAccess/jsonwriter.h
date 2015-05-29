#ifndef JSONWRITER_H
#define JSONWRITER_H
#include "../libs/rapidjson/rapidjson.h"
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/stringbuffer.h"
#include "../libs/rapidjson/writer.h"
#include "../res/vector.h"
#include "../res/Constants.h"




class JsonWriter
{
public:
    //Logic
    void writeMap(Vector<short> pMatriz, char pArreglo[]);
    void writeFamily(int* pFather, int* pMother, int* pFitness, char pArreglo[]);
    void writeFight(int pPopulation1, int pPopulation2, char pArreglo[]);

    //GUI

    void writeFamilyFromGUI(int raza, int pIndividuo, char pArreglo[]);
    void writeType(int pType, char pArreglo[]);



};

#endif // JSONWRITER_H
