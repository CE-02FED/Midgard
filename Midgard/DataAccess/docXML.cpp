
#include "docXML.h"
using namespace std;

docXML::docXML()
{
	pugi::xml_document doc;
	if (!doc.load_file("vheap.xml"))
	{
		cout << "Error al cargar el documento XML." << endl;
	}

	pugi::xml_node root_node;

	if (!(root_node = doc.child("vHeapData")))
	{
		cout << "El documento no es válido." << endl;
	}
        // se obtienen los datos del archivo xml

    vdebug = root_node.attribute("vdebug").as_bool();
    vdebug_file_name = root_node.attribute("vdebug_file_name").value();
    overweight = root_node.attribute("overweight").as_uint();
	size = root_node.attribute("size").as_uint();
	dump_frecuency = root_node.attribute("dump_frecuency").as_uint();
    dump_path = root_node.attribute("dump_path").value();
	vdebug_file_path = root_node.attribute("vdebug_file_path").as_uint();
	gc_frecuency = root_node.attribute("gc_frecuency").as_uint();

}

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
