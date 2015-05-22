#ifndef CONSTANTES_H_
#define CONSTANTES_H_
#include <string>
#include <iostream>
#include<sstream>
using namespace std;

class Constants{
    public:
    static Constants* getInstance();
        const static int SKILLSQUANTITY = 10;
        const static int MAXSKILL = 255;
        const static int MAXPOPULATION= 40;
        const static size_t DEFAULTELEMENTSIZE = 8;
        const static int START = 0;
        const static int GENERATIONS=100;
    //vheap
         int vHeapSize;
         float vHeapOverweight;
         bool vDebug;
         int dumpFrecuency;
         int port;
    string integerToString(int entero);
    string punteroToString(void* puntero);
    int stringToint(string st);
    private:
         Constants();
         static Constants* m_pInstancia;
         //xmlp heapxml;
};



#endif /* CONSTANTES_H_ */
