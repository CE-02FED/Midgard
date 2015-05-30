#ifndef CONSTANTES_H_
#define CONSTANTES_H_
#include <string>
#include <iostream>
#include<sstream>
using namespace std;

class Constants{
    public:    
        const static int SKILLSQUANTITY = 10;
        const static int MAXSKILL = 255;
        const static int MAXPOPULATION= 40;
        const static size_t DEFAULTELEMENTSIZE = 8;
        const static int START = 0;
        const static int GENERATIONS=100;
        static constexpr const char*  IMAGEN = "/home/javier/WorkspaceQT/GUI/imagenes GUI/imagen";

        static constexpr const char* IMAGEN_FORMATO = ".png";

};



#endif /* CONSTANTES_H_ */
