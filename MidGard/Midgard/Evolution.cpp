#include "Evolution.h"

Evolution::Evolution()
{
}

Population Evolution::evolvePopulation(Population pPopulation)
{
    Population* newPopulation = new Population(Constants::MAXPOPULATION, false);
    newPopulation->insertIndividualList(pPopulation.getFittest());


    for (int i =0;i<(Constants::MAXPOPULATION);i++)
    {
        Individuals FatherA = fathersSelection(pPopulation);
        Individuals FatherB = fathersSelection(pPopulation);
        Individuals* newIndividualsArray = CrossOver(FatherA, FatherB);

        Individuals& newA = newIndividualsArray[0];
        Individuals& newB = newIndividualsArray[1];

        newPopulation->insertIndividualList(&newA);
        newPopulation->insertIndividualList(&newB);

    }

    for(int i =0;i < (Constants::MAXPOPULATION);i++)
    {
        Mutation(newPopulation->getIndividualbyIndex(i));
    }
    return *newPopulation;
}

Individuals Evolution::fathersSelection(Population pPopulation)
{
    Population* fathers = new Population(_PoolFathersSize,false);

    for(int i=0;i<_PoolFathersSize;i++)
    {
        int tmpNum = rand()%pPopulation.getPopulationSize();
        Individuals* tmpIndividual = pPopulation.getFittest();
        fathers->insertIndividualList(tmpIndividual);
    }

    Individuals bestIndividual = fathers->getFittest();
    return bestIndividual;
}


void Evolution::Mutation(Individuals* pIndividual)
{
    for(int i=0;i < Constants::SKILLSQUANTITY ; i++)
    {
        if (rand()%100 <= _mutationRate)
        {
            pIndividual->getGenes()->Flip(rand()%80);
        }
    }
}





Individuals* Evolution::CrossOver(Individuals pFatherA, Individuals pFatherB)
{
    Individuals* newIndividualA = new Individuals();
    Individuals* newIndividualB = new Individuals();
    Individuals* tmpIndividuoA = new Individuals();
    Individuals* tmpIndividuoB = new Individuals();

    std::cout << "Father A Fitness: " <<std::to_string(pFatherA.getFitness()) << endl;
    std::cout << "Father B Fitness: " <<std::to_string(pFatherB.getFitness()) << endl;

    newIndividualA->setGene(pFatherA.getGenes()); // se le asigan los genes del padre al hijo A
    newIndividualB->setGene(pFatherB.getGenes()); // se le asignan los genes del padre al hijo B

    tmpIndividuoA->setGene( pFatherA.getGenes()); //se le asignan los genes del padre al hijo A
    tmpIndividuoB->setGene( pFatherB.getGenes()); //se le asignan los genes del padre al hijo B

            // Loop through genes
    for (int Indice = 0; Indice < Constants::SKILLSQUANTITY ; Indice++)
    {
        int tmpPuntoCruce = rand()%cantidadBits;
        size_t maskA = Mask << tmpPuntoCruce;
        size_t maskB = ~maskA;

        newIndividualA->getGenes()->andOperator(Indice,maskA); // se le aplica un AND la mask A a los genes del padre A
        newIndividualB->getGenes()->andOperator(Indice,maskB); // se le aplica un AND la mask B y a los genes del padre B

         // se mezclan los genes de ambos padres generan el nuevo individuo A
        newIndividualA->getGenes()->orOperator(Indice,newIndividualB->getGenes()->getByIndex(Indice));

        tmpIndividuoA->getGenes()->andOperator(Indice,maskB); // se le aplica un AND la mask B a los genes del padre A
        tmpIndividuoB->getGenes()->andOperator(Indice,maskA); // se le aplica un AND la mask A a los genes del padre B

        // se mezclan los genes de ambos padres generan el nuevo individuo B
        tmpIndividuoA->getGenes()->orOperator(Indice,tmpIndividuoB->getGenes()->getByIndex(Indice));


    }

    std::cout << "HijoA Fitness: " <<std::to_string(tmpIndividuoA->getFitness()) << endl;
    std::cout << "HijoB Fitness: " <<std::to_string(tmpIndividuoB->getFitness()) << endl;

    Individuals* GroupNewIndividuals[] = {newIndividualA,tmpIndividuoA};

    return *GroupNewIndividuals;
}


