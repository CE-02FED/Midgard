#include "jsonreader.h"

//GuiREader

Vector<int>* jsonReader::readMap(string pJson)
{
    rapidjson::Document document;
    const char* formatoJson = pJson.c_str();
    document.Parse<0>(formatoJson);

    rapidjson::Value& jsonHeight = document["height"];
    int Height= jsonHeight.GetInt();

    rapidjson::Value& jsonWidth = document["width"];
    int Width = jsonWidth.GetInt();

    rapidjson::Value& jsonMap = document["map"];
    string tmpMap=jsonMap.GetString();

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



Vector<int>* jsonReader::readFamily(string pJson)
{

    rapidjson::Document document;
    const char* formatoJson = pJson.c_str();
    document.Parse<0>(formatoJson);

    rapidjson::Value& jsonFatherID = document["Father"];
    int tmpFatherID= jsonFatherID.GetInt();

    rapidjson::Value& jsonMotherID = document["Mother"];
    int tmpMotherID = jsonMotherID.GetInt();

    rapidjson::Value& jsonFitness = document["Fitness"];
    int tmpFitness=jsonFitness.GetInt();

    Vector<int>* genealogia = new Vector<int>(3);

    *(*genealogia)[0]= tmpFatherID;
    *(*genealogia)[1]= tmpMotherID;
    *(*genealogia)[2]= tmpFitness;

    return genealogia;
}

Vector<int>* jsonReader::readFight(string pJson)
{
    rapidjson::Document document;
    const char* formatoJson = pJson.c_str();
    document.Parse<0>(formatoJson);

    rapidjson::Value& jsonPopulation1 = document["Raza1"];
    int Population1= jsonPopulation1.GetInt();

    rapidjson::Value& jsonPopulation2 = document["Raza2"];
    int Population2= jsonPopulation2.GetInt();

    Vector<int>* arregloRazas = new Vector<int>(2);
    arregloRazas[0] = Population1;
    arregloRazas[0] = Population2;

    return arregloRazas;

}



// LogicReader




Vector<int>* jsonReader::readFamilyFromGUI(string pJson)
{
    rapidjson::Document document;
    const char* formatoJson = pJson.c_str();
    document.Parse<0>(formatoJson);

    rapidjson::Value& jsonRaza = document["raza"];
    int Raza= jsonRaza.GetInt();

    rapidjson::Value& jsonIndividuo = document["individuo"];
    int IndividuoID= jsonIndividuo.GetInt();

    Vector<int>* arregloFamilia = new Vector<int>(2);

    arregloFamilia[0] = Raza;
    arregloFamilia[1] = IndividuoID;

    return arregloFamilia;
}


int jsonReader::readType(string pJson)
{
    rapidjson::Document document;
    cout << "before return"<< endl;

    const char* formatoJson = pJson.c_str();
    document.Parse<0>(formatoJson);

    rapidjson::Value& jsonType = document["type"];
    int Type =jsonType.GetInt();

    return Type;
}
