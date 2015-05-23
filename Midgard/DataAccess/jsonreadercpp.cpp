#include "jsonreadercpp.h"

Vector<int>* jsonReaderCpp::readMap (string pJson)
{
    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful= reader.parse(pJson,root,false);
    if (!parsingSuccessful)
    {
        cout<<"Failed to parse configuration\n"
              << reader.getFormattedErrorMessages();
    }
    cout<<root.toStyledString()<<endl;

    int Height= stoi(root["height"].asString());
    int Width= stoi(root["width"].asString());
    string tmpMap=root["map"].asString();

    Vector<int>* newMatriz = new Vector<int>(Height, Width) ;

        string numero = "";
        int index = 0, jindex = 0;
        for (int i = 0; i < tmpMap.length(); i++) {
            if (index >= Height) {
                break;
            }
            if (jindex >= Width) {
                jindex = 0;
                index++;
            }
            if (tmpMap[i] == '#') {
                (*newMatriz)[index][jindex] = stoi(numero);
                jindex++;
                numero = "";
            }
            else {
                numero += tmpMap[i];
            }
        }
  return newMatriz;
}

Vector<int>* jsonReaderCpp::readFight(string pJson)
{
    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful= reader.parse(pJson,root,false);
    if (!parsingSuccessful)
    {
        cout<<"Failed to parse configuration\n"
              << reader.getFormattedErrorMessages();
    }
    cout<<root.toStyledString()<<endl;

    int Population1= stoi(root["Raza1"].asString());
    int Population2= stoi(root["Raza2"].asString());

    Vector<int>* arregloRazas = new Vector<int>(2);
    *(*arregloRazas)[0] = Population1;
    *(*arregloRazas)[1] = Population2;

    return arregloRazas;

}

Vector<int>* jsonReaderCpp::readFamily(string pJson)
{

    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful= reader.parse(pJson,root,false);
    if (!parsingSuccessful)
    {
        cout<<"Failed to parse configuration\n"
              << reader.getFormattedErrorMessages();
    }
    cout<<root.toStyledString()<<endl;

    int tmpFatherID= stoi(root["Father"].asString());
    int tmpMotherID= stoi(root["Mother"].asString());
    int tmpFitness= stoi(root["Fitness"].asString());

    Vector<int>* genealogia = new Vector<int>(3);

    *(*genealogia)[0]= tmpFatherID;
    *(*genealogia)[1]= tmpMotherID;
    *(*genealogia)[2]= tmpFitness;

    return genealogia;
}

// LogicReader

Vector<int>* jsonReaderCpp::readFamilyFromGUI(string pJson)
{
    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful= reader.parse(pJson,root,false);
    if (!parsingSuccessful)
    {
        cout<<"Failed to parse configuration\n"
              << reader.getFormattedErrorMessages();
    }
    cout<<root.toStyledString()<<endl;

    int Raza= stoi(root["Raza"].asString());
    int IndividuoID= stoi(root["IndividuoID"].asString());
    cout << "estoy readFromGUiFamili" << endl;

    Vector<int>* arregloFamilia = new Vector<int>(2);

    *(*arregloFamilia)[0] = Raza;
    *(*arregloFamilia)[1] = IndividuoID;

    return arregloFamilia;
}

int jsonReaderCpp::readType(string pJson)
{
    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful= reader.parse(pJson,root,false);
    if (!parsingSuccessful)
    {
        cout<<"Failed to parse configuration\n"
              << reader.getFormattedErrorMessages();
    }
    cout<<root.toStyledString()<<endl;

    int Type= stoi(root["type"].asString());


    return Type;
}

