//Header file
#ifndef DOCXML_H_
#define DOCXML_H_
#include <iostream>
#include <string>
#include "../res/pugiconfig.hpp"
#include "pugixml.hpp"

//home/david/Documents/Midgard26-05-2015/res/MidgardConstants.xml";
static constexpr const char* xmlPath = "/home/david/Documents/cLion-Projects/Midgard/Midgard/res/MidgardConstants.xml";


using namespace std ;

class docXML {
private:    
    unsigned int maxPopulation, BITS_PER_SECOND,matrizWidth,matrizHeight, generations;
    string matriz,ARDUINO_PATH;
    pugi::xml_document doc;
    pugi::xml_node rootNode;

public:

    docXML();
    char* stringToChar(string toConvert);
    const pugi::xml_document& loadFile(const char* document);
    const pugi::xml_document& getDoc() const {
        return doc;
    }

    int getGenerations(){return this->generations;}    

    int getMaxPopulation(){ return this->maxPopulation;}

    int getvBitsPerSecond(){return this->BITS_PER_SECOND;}

    string getArduinoPath(){return this->ARDUINO_PATH;}

    int getMatrizWidth(){return this->matrizWidth;}

    int getMatrizHeight(){return this->matrizHeight;}

    string getMatriz(){return this->matriz;}
};

#endif
