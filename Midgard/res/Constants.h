#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>
#include <iostream>
#include "../DataAccess/docXML.h"
#include<sstream>
#include <cstring>





using namespace std;

class Constants{
    public:
    static Constants* getInstance();

        const static int SKILLSQUANTITY=10;
        const static int MAXSKILL=255;
        static const size_t DEFAULTELEMENTSIZE = 8;
        static const int START = 0;

        string MATRIZ;
        int WIDTH;
        int HEIGHT;
        int MAXPOPULATION;                
        int GENERATIONS;
        int BITS_PER_SECOND =19200;
        string ARDUINO_PATH= "/dev/ttyACM0";

    //vheap
    string integerToString(int entero);
    string punteroToString(void* puntero);
    int stringToint(string st);

    private:
         Constants();
         docXML* xmlDocument;
         static Constants* m_pInstancia;
         //xmlp heapxml;
};



#endif /* CONSTANTS_H_ */
