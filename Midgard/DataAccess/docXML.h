//Header file
#ifndef DOCXML_H_
#define DOCXML_H_
#include <iostream>
#include <string>
#include "../res/pugiconfig.hpp"
#include "pugixml.hpp"

static constexpr const char* xmlPath = "/home/david/Documents/cLion-Projects/Midgard/Midgard/res/MidgardConstants.xml";


using namespace std ;

class docXML {
private:    
    unsigned int elmentSize, maxPopulation, MaxSkill, skillsQuantity,matrizWidth,matrizHeight, generations;
    string matriz;
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

    int getElementSize(){ return this->elmentSize;}

    int getMaxPopulation(){ return this->maxPopulation;}

    int getvMaxSkill(){return this->MaxSkill;}

    int getSkillQuantity(){return this->skillsQuantity;}

    int getMatrizWidth(){return this->matrizWidth;}

    int getMatrizHeight(){return this->matrizHeight;}

    string getMatriz(){return this->matriz;}
};

#endif
