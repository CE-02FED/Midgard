#include "jsonwritercpp.h"


 //LogicWriter

string jsonWriterCpp::writeMap(Vector<int>* pMatriz)
{
    //{"type":"1"}"{\"type\":\"1\"}"
    string pMe="{\"type\" : ";
           string Height=to_string((pMatriz)->getHeight());
           string type=to_string(1);
           string Width =to_string((pMatriz)->getWidth());

           pMe.append("\""+type+"\" ,");
           pMe.append("\"height\" : \""+Height+"\" ,");
           pMe.append("\"width\" : \""+Width+"\" ,");
           pMe.append("\"map\" :\"");
           string newMatriz= "";

           for(int i =0; i < (pMatriz)->getHeight();i++)
           {
               for(int j=0; j<(pMatriz)->getWidth();j++ )
               {
                   if (i>24 || j>24)
                   {
                       cout << "se paso" << endl;
                   }
                   newMatriz += to_string((*pMatriz)[i][j]) + "#" ;
               }

           }

        cout << "estoy aqui en json WRITE" << endl;
        pMe.append(newMatriz);
        pMe.append("\" }");
        //pMatriz->print();
        //cout<<pMe<<endl;
        return pMe;
}

string jsonWriterCpp::writeFamily(int pFather, int pMother, int pFitness)
{

    string pMe="{\"type\" : ";
           string Father=to_string(pFather);
           string type=to_string(2);
           string Mother=to_string(pMother);
           string Fitness=to_string(pFitness);


           pMe.append("\""+type+"\" ,");
           pMe.append("\"Father\" : \""+Father+"\" ,");
           pMe.append("\"Mother\" : \""+Mother+"\" ,");
           pMe.append("\"Fitness\" : \""+Fitness+"\" }");


        //pMe.append(" }");
        cout << "mando write family" <<endl;
        cout<<pMe<<endl;
        return pMe;
}

string jsonWriterCpp::writeFight(int pPopulation1, int pPopulation2)
{
    string pMe="{\"type\" : ";
           string type=to_string(3);
           string Population1=to_string(pPopulation1);
           string Population2=to_string(pPopulation2);

           pMe.append("\""+type+"\" ,");
           pMe.append("\"Raza1\" : \""+Population1+"\" ,");
           pMe.append("\"Raza2\" : \""+Population2+"\" ");

           pMe.append(" }");
           cout<<pMe<<endl;
           return pMe;
}

string jsonWriterCpp::writePuebloInfo(int pLowestFitness, int pHighestFitnesss, int pAmountPeople)
{
    string pMe="{\"type\" : ";
    string type=to_string(3);
           string lowestFitness=to_string(pLowestFitness);
           string highestFitness=to_string(pHighestFitnesss);
           string peopleAmount=to_string(pAmountPeople);
           pMe.append("\""+type+"\" ,");
           pMe.append("\"Fittest\" : \""+highestFitness+"\" ,");
           pMe.append("\"worstFitness\" : \""+lowestFitness+"\" ,");
           pMe.append("\"amountPeople\" : \""+peopleAmount+"\" }");                                 


        //pMe.append(" }");
        cout << "mando write PuebloInfo" <<endl;
        cout<<pMe<<endl;
        return pMe;
}

// GUIWRITER

string jsonWriterCpp::writeFamilyFromGUI(int pRaza, int pIndividuoID)
{
    string pMe="{\"type\" : ";
           string type=to_string(2);
           string Raza=to_string(pRaza);
           string IndividuoID=to_string(pIndividuoID);

           pMe.append("\""+type+"\" ,");
           pMe.append("\"Raza\" : \""+Raza+"\" ,");
           pMe.append("\"IndividuoID\" : \""+IndividuoID+"\" ");

           pMe.append(" }");
           cout<<pMe<<endl;
           return pMe;
}

string jsonWriterCpp::writeType(int pType)
{
    string pMe="{\"type\" : ";
           string type=to_string(pType);

           pMe.append("\""+type+"\" ");

           pMe.append(" }");
           cout<<pMe<<endl;
           return pMe;
}

