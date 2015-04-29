//Header file
#ifndef DOCXML_H_
#define DOCXML_H_
#include <iostream>
#include <string>
#include "pugiconfig.hpp"
#include "pugixml.hpp"
using namespace std ;

class docXML {
private:
    string vdebug_file_name, dump_path;
    bool vdebug;
	float overweight;
    unsigned int size, dump_frecuency, vdebug_file_path, gc_frecuency;

public:
	docXML();
	void setSize(int pSize){this->size = pSize;}
	int getSize(){ return this->size;}
    void setDumpFrecuency(int pDumpFrecuency){this->dump_frecuency = pDumpFrecuency;}
	int getDumpFrecuency(){ return this->dump_frecuency;}
    void setDumpPath(std::string pDumpPath){this->dump_path = pDumpPath;}
    std::string getDumpPath(){return this->dump_path;}
	void setvDebugFilePath(int pvDebugFilePath){this->vdebug_file_path = pvDebugFilePath;}
	int getvDebugFilePath(){return this->vdebug_file_path;}
	void setGCFrecuency(int pGCFrecuency){this->gc_frecuency = pGCFrecuency;}
	int getGCFrecuency(){return this->gc_frecuency;}
	void setOverweight(int pOverweight){this->overweight = pOverweight;}
    int getOverweight(){return this->overweight;}
    void setvDebug(bool pvDebug){this->vdebug = pvDebug;}
    bool getvDebug(){return this->vdebug;}
	void setvDebugFileName(int pvDebugFileName){this->vdebug_file_name = pvDebugFileName;}
	std::string getvDebugFileName(){return this->vdebug_file_name;}
};

#endif
