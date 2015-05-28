
#include "docXML.h"
using namespace std;

docXML::docXML()
{    
    pugi::xml_document doc;
    if (!doc.load_file(xmlPath))
	{
		cout << "Error al cargar el documento XML." << endl;
	}

	pugi::xml_node root_node;

    if (!(root_node = doc.child("ConstantsData")))
	{
		cout << "El documento no es válido." << endl;
	}
        // se obtienen los datos del archivo xml

    maxPopulation = root_node.attribute("maxPopulation").as_uint();


    ARDUINO_PATH = root_node.attribute("arduinoPath").value();
    BITS_PER_SECOND = root_node.attribute("bitsPerSecond").as_uint();
    matrizWidth = root_node.attribute("matrizWidth").as_uint();
    matrizHeight = root_node.attribute("matrizHeight").as_uint();
    matriz = root_node.attribute("matriz").value();
    generations= root_node.attribute("GENERATIONS").as_int();
}
const pugi::xml_document& docXML::loadFile(const char* document){
     if (!doc.load_file(document)){
            cerr << "Error al cargar el documento XML." << endl;
                }
     return doc;
 }
