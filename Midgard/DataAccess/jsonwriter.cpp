#include "jsonwriter.h"

//LogicWriter

void JsonWriter::writeMap(Vector<short> pMatriz,char pArreglo[])
{
    rapidjson::Document document;
    const char* formatoJson = "{\"type\":\"1\", \"height\":\"0\", \"width\":\"0\",\"map\":\"0\" }";
    document.Parse<0>(formatoJson);

    rapidjson::Value& type = document["type"];
    type.SetInt(1);

    rapidjson::Value& Height = document["height"];
    Height.SetInt(pMatriz.getHeight());

    rapidjson::Value& Width = document["width"];
    Width.SetInt(pMatriz.getWidth());

    rapidjson::Value& Map = document["map"];
    string newMatriz= "";

    for(int i =0; i < pMatriz.getHeight(); i++)
    {
        for(int j=0; j<pMatriz.getWidth();j++ )
        {
            newMatriz += to_string(pMatriz[i][j]) + "#" ;
        }
    }

    Map.SetString(newMatriz.c_str());
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    strcpy(pArreglo,buffer.GetString());
}


void JsonWriter::writeFamily(int *pFather, int *pMother, int *pFitness, char pArreglo[])
{
    rapidjson::Document document;
    const char* formatoJson = "{\"type\":\"0\", \"Father\":\"0\", \"Mother\":\"0\",\"Fitness\":\"0\" }";
    document.Parse<0>(formatoJson);

    rapidjson::Value& type = document["type"];
    type.SetInt(2);

    rapidjson::Value& Father = document["Father"];
    Father.SetInt(pFather);

    rapidjson::Value& Mother = document["Mother"];
    Mother.SetInt(pMother);

    rapidjson::Value& Fitness = document["Fitness"];
    Fitness.SetInt(pFitness);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    strcpy(pArreglo,buffer.GetString());
}

void JsonWriter::writeFight(int pPopulation1, int pPopulation2, char pArreglo[])
{
    rapidjson::Document document;
    const char* formatoJson = "{\"type\":\"0\", \"Raza1\":\"0\", \"Raza2\":\"0\"}";
    document.Parse<0>(formatoJson);

    rapidjson::Value& type = document["type"];
    type.SetInt(3);

    rapidjson::Value& Raza1 = document["Raza1"];
    Raza1.SetInt(pPopulation1);

    rapidjson::Value& Raza2 = document["Raza2"];
    Raza2.SetInt(pPopulation2);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    strcpy(pArreglo,buffer.GetString());


}







// GUIWRITER

void JsonWriter::writeFamilyFromGUI(int raza, int pIndividuo, char pArreglo[])
{
    rapidjson::Document document;
    const char* formatoJson = "{\"type\":\"0\", \"Raza\":\"0\", \"IndividuoID\":\"0\"}";
    document.Parse<0>(formatoJson);

    rapidjson::Value& type = document["type"];
    type.SetInt(2);

    rapidjson::Value& Raza = document["Raza"];
    Raza.SetInt(raza);

    rapidjson::Value& Individuo = document["IndividuoID"];
    Individuo.SetInt(pIndividuo);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    strcpy(pArreglo,buffer.GetString());
}

void JsonWriter::writeType(int pType, char pArreglo[])
{
    rapidjson::Document document;
    const char* formatoJson = "{\"type\":\"0\"}";
    document.Parse<0>(formatoJson);

    rapidjson::Value& type = document["type"];
    type.SetInt(pType);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    strcpy(pArreglo,buffer.GetString());
}

