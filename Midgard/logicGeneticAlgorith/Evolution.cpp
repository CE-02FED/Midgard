#include "Evolution.h"

Evolution::Evolution()
{
}

/**
 * @brief Evolution::evolvePopulation
 * Se encarga de hacer el crossOver y la mutacion
 *
 * @param pPopulation: La poblacion que se desea reproducir
 * @return La totalmente nueva poblacion que se genera a partir de la reproduccion
 */


Population Evolution::evolvePopulation(Population pPopulation)
{
    Population* newPopulation = new Population(1, false);
    newPopulation->insertIndividualList(pPopulation.getFittest());


    for (int i =0;i<((Constants::MAXPOPULATION)/10);i++)
    {
        Individuals* FatherA = fathersSelection(pPopulation);

        Individuals* FatherB = fathersSelection(pPopulation);
        lista<Individuals>* newIndividualsList = CrossOver(*FatherA, *FatherB);

        /*Individuals* newA=new Individuals();
        Individuals* newB=new Individuals();
        newA = newIndividualsArray[0];
        newB = newIndividualsArray[1];*/
        //std::cout<<"Fitness newA2 "<<*(newA->getFitness())<<std::endl;
        //std::cout<<"Fitness newB2 "<<*(newB->getFitness())<<std::endl;


        pPopulation.insertIndividualList(newIndividualsList->getElemento(0));
        pPopulation.upPopulation();

        pPopulation.insertIndividualList(newIndividualsList->getElemento(1));
        pPopulation.upPopulation();
    }


    for(int i =0;i < pPopulation.getPopulationSize();i++)
    {

        Mutation(pPopulation.getIndividualbyIndex(i));
    }
    return pPopulation;
}


/**
 * @brief Evolution::fathersSelection
 * Se encarga de seleccionar a un grupo de padres de la poblacion total
 * seleccionando _PoolFathersSize de cantidad de padres, y de este grupo, se
 * Escoge al individuo con mas fitness y luego de esto, se envia al individuo con mas
 * Fitness de este grupo
 * @param pPopulation: La poblacion general para seleccionar los padres
 * @return
 */
Individuals* Evolution::fathersSelection(Population pPopulation)
{


    int totalFitness=pPopulation.getTotalFitness();
    Individuals* fathers[100];

    int j=0;
    int i=0;
    int redondeo=round(((*(pPopulation.getIndividualbyIndex(0)->getFitness())+0.0)/totalFitness)*100);
    while(i<99){



        if((redondeo)==i){

            if(j!=(pPopulation.getPopulationSize()-1)){
            j++;
            }
            //std::cout<<"redondeo: "<<redondeo<<std::endl;
            //std::cout<<"num Ele "<<j<<std::endl;
            //std::cout<<"fitness FS "<<*(pPopulation.getIndividualbyIndex(j)->getFitness())<<std::endl;
            redondeo=redondeo+round(((*(pPopulation.getIndividualbyIndex(j)->getFitness())+0.0)/totalFitness)*100);
        }
        fathers[i]=pPopulation.getIndividualbyIndex(j);
        i++;
     }

    int ran=randomClass::getRandom(98);
    Individuals* randomFather= fathers[ran];
    return randomFather;


    ;
}

/**
 * @brief Evolution::Mutation
 * Se encarga de mutar a un bit del array de cromosomas del individuo
 * @param pIndividual: Individuo a mutar
 */
void Evolution::Mutation(Individuals* pIndividual)
{
    for(int i=0;i < Constants::SKILLSQUANTITY ; i++)
    {
        if (randomClass::randRange(0.0,10.0) <= _mutationRate)
        {

           // pIndividual->getGenes()->Flip(randomClass::getRandom(80));
            //std::cout<< "entro mut saio flip" << std::endl;
        }

    }
}




/**
 * @brief Evolution::CrossOver
 * Se aplican mascaras con los operadores and y or para mezclar los genes
 * Del Padre A con los del Padre B
 * Para asi producir 2 hijos, Hijo A e Hijo B los cuales se meten en un array
 * y se devuelven en el return
 * @param pFatherA: Padre dominante que se reproducira
 * @param pFatherB: Padre recesivo que se reproducira
 * @return Array de Individuals que contiene al Hijo A e Hijo B
 */
lista<Individuals>* Evolution::CrossOver(Individuals pFatherA, Individuals pFatherB)
{
   /* Individuals* newIndividualA = new Individuals();
    Individuals* newIndividualB = new Individuals();
    Individuals* tmpIndividualA = new Individuals();
    Individuals* tmpIndividualB = new Individuals();

    newIndividualA->setIndividualID(1);
    newIndividualB->setIndividualID(2);
    tmpIndividualA->setIndividualID(3);
    tmpIndividualB->setIndividualID(4);



    newIndividualA->setGene(pFatherA.getGenes()); // se le asigan los genes del padre al hijo A
    newIndividualB->setGene(pFatherB.getGenes()); // se le asignan los genes del padre al hijo B

    tmpIndividualA->setGene( pFatherA.getGenes()); //se le asignan los genes del padre al hijo A
    tmpIndividualB->setGene( pFatherB.getGenes()); //se le asignan los genes del padre al hijo B*/
    //std::cout << "Father A Fitness: " <<std::to_string(*(pFatherA.getFitness())) << endl;
    //std::cout << "Father B Fitness: " <<std::to_string(*(pFatherB.getFitness())) << endl;

    BitVector* genesIndividualA = new BitVector(Constants::SKILLSQUANTITY);
    *genesIndividualA=*(pFatherA.getGenes());
    BitVector* genesIndividualB = new BitVector(Constants::SKILLSQUANTITY);
     *genesIndividualB=*(pFatherB.getGenes());

    BitVector* tmpGenesIndividualA =  new BitVector(Constants::SKILLSQUANTITY);
    *tmpGenesIndividualA=*(pFatherA.getGenes());
    BitVector* tmpGenesIndividualB = new BitVector(Constants::SKILLSQUANTITY);
    *tmpGenesIndividualB=*(pFatherB.getGenes());


    for (int Indice = 0; Indice < Constants::SKILLSQUANTITY ; Indice++)
    {
        int tmpPuntoCruce = rand()%cantidadBits;
        u_int8_t tmpMask = (char) Mask;
        u_int8_t maskA = (tmpMask << tmpPuntoCruce);
        u_int8_t maskB = ~(maskA);

        genesIndividualA->andOperator(Indice,maskB);
        //cout <<"Cualidad "<<Indice<<" F1 and "<< to_string(genesIndividualA->getByIndex(Indice))<<endl;
        genesIndividualB->andOperator(Indice,maskA);
        //cout <<"Cualidad "<<Indice<<" F2 and "<< to_string(genesIndividualB->getByIndex(Indice))<<endl;
        genesIndividualA->orOperator(Indice,genesIndividualB->getByIndex(Indice));
        //cout <<"Cualidad IndA: "<<Indice<<" New or "<< to_string(genesIndividualA->getByIndex(Indice))<<endl;

        tmpGenesIndividualA->andOperator(Indice,maskA);
        //cout <<"Cualidad "<<Indice<<" F1 and "<< to_string(tmpGenesIndividualA->getByIndex(Indice))<<endl;
        tmpGenesIndividualB->andOperator(Indice,maskB);
        //cout <<"Cualidad "<<Indice<<" F2 and "<< to_string(tmpGenesIndividualA->getByIndex(Indice))<<endl;
        tmpGenesIndividualA->orOperator(Indice,tmpGenesIndividualB->getByIndex(Indice));
        //cout <<"Cualidad IndB: "<<Indice<<" New or "<< to_string(tmpGenesIndividualA->getByIndex(Indice))<<endl;

    }

    Individuals* newIndividualA = new Individuals();
    newIndividualA->setGene(*genesIndividualA);
    Individuals* newIndividualB = new Individuals();
    newIndividualB->setGene(*tmpGenesIndividualA);





    //cout<< "fitness New A "<< *(*(newIndividualA)).getFitness()<<endl;

    //cout<< "fitness New B "<< *(*(newIndividualB)).getFitness()<<endl;
    lista<Individuals>* list= new lista<Individuals>();
    list->agregar(newIndividualA,0);
    list->agregar(newIndividualB,0);
    Individuals Array[2]={(newIndividualA),(newIndividualB)};
    /*lista<Individuals> GroupNewIndividuals;
    GroupNewIndividuals.agregar(newIndividualA,0);
    GroupNewIndividuals.agregar(newIndividualB,0);*/














/*            // Loop through genes
    for (int Indice = 0; Indice < Constants::SKILLSQUANTITY ; Indice++)
    {
        int tmpPuntoCruce = rand()%cantidadBits;

        u_int8_t tmpMask = (char) Mask; //1
        u_int8_t maskA = (tmpMask << tmpPuntoCruce);
        u_int8_t     maskB = ~(maskA);

        //cout<<"MaskA "<<to_string(maskA)<<endl;
        //cout<<"MaskB "<<to_string(maskB)<<endl;

// INDIVIDUO A

        newIndividualA->getGenes()->andOperator(Indice,maskA);
        //cout <<"Cualidad "<<Indice<<" F1 and "<< to_string(newIndividualA->getGenes()->getByIndex(Indice))<<endl;

        newIndividualB->getGenes()->andOperator(Indice,maskB);
        //cout <<"Cualidad "<<Indice<<" F2 and "<< to_string(newIndividualB->getGenes()->getByIndex(Indice))<<endl;

        newIndividualB->getGenes()->orOperator(Indice,newIndividualA->getGenes()->getByIndex(Indice));// Individuo 1 Paso3
        cout <<"Cualidad IndA: "<<Indice<<" New or "<< to_string(newIndividualB->getGenes()->getByIndex(Indice))<<endl;

// INDIVIDUO B

        tmpIndividualA->getGenes()->andOperator(Indice,maskB);
        //cout <<"Cualidad "<<Indice<<" F1 and "<< to_string(tmpIndividualA->getGenes()->getByIndex(Indice))<<endl;

        tmpIndividualB->getGenes()->andOperator(Indice,maskA);
        //cout <<"Cualidad "<<Indice<<" F2 and "<< to_string(tmpIndividualB->getGenes()->getByIndex(Indice))<<endl;

        tmpIndividualB->getGenes()->orOperator(Indice,tmpIndividualA->getGenes()->getByIndex(Indice));// Individuo 2 Paso3
        cout <<"Cualidad IndB: "<<Indice<<" New or "<< to_string(tmpIndividualB->getGenes()->getByIndex(Indice))<<endl;
    }


    cout<< "fitness New A "<< (newIndividualB->getFitness())<<endl;
    cout << "individual A ID: " << newIndividualB->getIndividualID() << endl;

    cout<< "fitness New B "<< (tmpIndividualB->getFitness())<<endl;
    cout << "individual B ID: " << tmpIndividualB->getIndividualID() << endl;

    Individuals* GroupNewIndividuals[] = {newIndividualB,tmpIndividualB};
*/
    /*int tmpCruce = randomClass::randRange(1,10);

    for (int Indice = 0; Indice < tmpCruce ; Indice++)
    {
        newIndividualA->getGenes()->insertByIndex(Indice,pFatherA.getGenes()->getByIndex(Indice));
        newIndividualB->getGenes()->insertByIndex(Indice,pFatherB.getGenes()->getByIndex(Indice));
    }
    for(int Indice =tmpCruce; Indice < (10-tmpCruce);Indice++)
    {
        newIndividualA->getGenes()->insertByIndex(Indice,pFatherB.getGenes()->getByIndex(Indice));
        newIndividualB->getGenes()->insertByIndex(Indice,pFatherA.getGenes()->getByIndex(Indice));
    }*/

    //std::cout << "HijoA Fitness: " <<std::to_string(newIndividualA->getFitness()) << endl;
    //std::cout << "HijoB Fitness: " <<std::to_string(newIndividualB->getFitness()) << endl;

    //Individuals* GroupNewIndividuals[] = {newIndividualA,newIndividualB};


    return list;
}


