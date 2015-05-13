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
    Population* newPopulation = new Population(Constants::MAXPOPULATION, false);
    newPopulation->insertIndividualList((pPopulation.getFittest()));


    for (int i =0;i<((Constants::MAXPOPULATION)/2);i++)
    {
        Individuals FatherA = fathersSelection(pPopulation);

        Individuals FatherB = fathersSelection(pPopulation);
        Individuals* newIndividualsArray = CrossOver(FatherA, FatherB);

        Individuals& newA = newIndividualsArray[0];
        Individuals& newB = newIndividualsArray[1];

        newPopulation->insertIndividualList(&newA);

        newPopulation->insertIndividualList(&newB);

    }


    for(int i =0;i < newPopulation->getPopulationSize();i++)
    {

        Mutation(newPopulation->getIndividualbyIndex(i));
    }
    return *newPopulation;
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
Individuals Evolution::fathersSelection(Population pPopulation)
{
    Population* fathers = new Population(_PoolFathersSize,false);


    for(int i=0;i<_PoolFathersSize;i++)
    {        
        int tmpNum = rand()%pPopulation.getPopulationSize();       
        Individuals tmpIndividual = pPopulation.getFittest();
        fathers->insertIndividualList(&tmpIndividual);

    }


    Individuals bestIndividual = fathers->getFittest();
    return bestIndividual;
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
Individuals* Evolution::CrossOver(Individuals pFatherA, Individuals pFatherB)
{
   /* Individuals* newIndividualA = new Individuals();
    Individuals* newIndividualB = new Individuals();
    Individuals* tmpIndividualA = new Individuals();
    Individuals* tmpIndividualB = new Individuals();

    newIndividualA->setIndividualID(1);
    newIndividualB->setIndividualID(2);
    tmpIndividualA->setIndividualID(3);
    tmpIndividualB->setIndividualID(4);

   // std::cout << "Father A Fitness: " <<std::to_string(pFatherA.getFitness()) << endl;
    //std::cout << "Father B Fitness: " <<std::to_string(pFatherB.getFitness()) << endl;

    newIndividualA->setGene(pFatherA.getGenes()); // se le asigan los genes del padre al hijo A
    newIndividualB->setGene(pFatherB.getGenes()); // se le asignan los genes del padre al hijo B

    tmpIndividualA->setGene( pFatherA.getGenes()); //se le asignan los genes del padre al hijo A
    tmpIndividualB->setGene( pFatherB.getGenes()); //se le asignan los genes del padre al hijo B*/

    BitVector* genesIndividualA = pFatherA.getGenes();
    BitVector* genesIndividualB = pFatherB.getGenes();

    BitVector* tmpGenesIndividualA =  pFatherA.getGenes();
    BitVector* tmpGenesIndividualB = pFatherB.getGenes();


    for (int Indice = 0; Indice < Constants::SKILLSQUANTITY ; Indice++)
    {
        int tmpPuntoCruce = rand()%cantidadBits;
        u_int8_t tmpMask = (char) Mask;
        u_int8_t maskA = (tmpMask << tmpPuntoCruce);
        u_int8_t maskB = ~(maskA);

        //cout<<"MaskA "<<to_string(maskA)<<endl;
        //cout<<"MaskB "<<to_string(maskB)<<endl;


        genesIndividualA->andOperator(Indice,maskA);
        //cout <<"Cualidad "<<Indice<<" F1 and "<< to_string(genesIndividualA->getByIndex(Indice))<<endl;
        genesIndividualB->andOperator(Indice,maskB);
        //cout <<"Cualidad "<<Indice<<" F2 and "<< to_string(genesIndividualB->getByIndex(Indice))<<endl;
        genesIndividualA->orOperator(Indice,genesIndividualB->getByIndex(Indice));
        cout <<"Cualidad IndA: "<<Indice<<" New or "<< to_string(genesIndividualA->getByIndex(Indice))<<endl;

        tmpGenesIndividualA->andOperator(Indice,maskA);
        //cout <<"Cualidad "<<Indice<<" F1 and "<< to_string(tmpGenesIndividualA->getByIndex(Indice))<<endl;
        tmpGenesIndividualB->andOperator(Indice,maskB);
        //cout <<"Cualidad "<<Indice<<" F2 and "<< to_string(tmpGenesIndividualA->getByIndex(Indice))<<endl;
        tmpGenesIndividualA->orOperator(Indice,tmpGenesIndividualB->getByIndex(Indice));
        cout <<"Cualidad IndB: "<<Indice<<" New or "<< to_string(tmpGenesIndividualA->getByIndex(Indice))<<endl;

    }

    Individuals* newIndividualA = new Individuals(genesIndividualA);
    Individuals* newIndividualB = new Individuals(tmpGenesIndividualA);



    cout<< "fitness New A "<< (newIndividualA->getFitness())<<endl;

    cout<< "fitness New B "<< (newIndividualB->getFitness())<<endl;

    Individuals* GroupNewIndividuals[] = {newIndividualB,newIndividualB};













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


    return *GroupNewIndividuals;
}


