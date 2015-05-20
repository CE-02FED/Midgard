//Header file
#ifndef DOCXML_H_
#define DOCXML_H_
#include <iostream>
#include <string>
#include "../res/pugiconfig.hpp"
#include "pugixml.hpp"
using namespace std ;

class docXML {
private:    
    unsigned int elmentSize, maxPopulation, MaxSkill, skillsQuantity,matrizWidth,matrizHeight;
    string matriz;

public:

    docXML();

    int getElementSize(){ return this->elmentSize;}

    int getMaxPopulation(){ return this->maxPopulation;}

    int getvMaxSkill(){return this->MaxSkill;}

    int getSkillQuantity(){return this->skillsQuantity;}

    int getMatrizWidth(){return this->matrizWidth;}

    int getMatrizHeight(){return this->matrizHeight;}

    string getMatriz(){return this->matriz;}
};

#endif
