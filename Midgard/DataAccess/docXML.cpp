
#include "docXML.h"
using namespace std;

docXML::docXML()
{
    pugi::xml_document doc;
    if (!doc.load_file("/home/javier/WorkspaceQT/Midgard/MidgardConstants.xml"))
	{
		cout << "Error al cargar el documento XML." << endl;
	}

	pugi::xml_node root_node;

    if (!(root_node = doc.child("ConstatsData")))
	{
		cout << "El documento no es válido." << endl;
	}
        // se obtienen los datos del archivo xml

    elmentSize = root_node.attribute("elementSize").as_uint();
    maxPopulation = root_node.attribute("maxPopulation").as_uint();
    MaxSkill = root_node.attribute("maxSkill").as_uint();
    skillsQuantity = root_node.attribute("skillsQuantity").as_uint();
    matrizWidth = root_node.attribute("matrizWidth").as_uint();
    matrizHeight = root_node.attribute("matrizHeight").as_uint();
    matriz = root_node.attribute("matriz").value();
    generations= root_node.attribute("generaciones").as_int();
}
const pugi::xml_document& docXML::loadFile(const char* document){
     if (!doc.load_file(document)){
            cerr << "Error al cargar el documento XML." << endl;
                }
     return doc;
 }
/*char* docXML::stringToChar(string toConvert){
    char *y = new char[toConvert.length() + 1];
    strcpy(y, toConvert.c_str());
    return y;
}*/


/*int main()
{
	docXML* doc = new docXML();
	cout << "size: "<< doc->getSize() << endl;
	cout << "gcfrec: "<< doc->getGCFrecuency() << endl;
	cout << "overw: "<< doc->getOverweight() << endl;
	cout << "vdebug: "<< doc->getvDebug() << endl;
	cout << "vdebugfilepath: "<< doc->getvDebugFilePath() << endl;
	doc->setvDebugFilePath(doc->getvDebugFilePath()+2);
	cout << "vdebugfilepath: "<< doc->getvDebugFilePath() << endl;
}
*/
