#include "Evolution.h"

Evolution::Evolution()
{
     _random = new Random();
}

/**
 * @brief Evolution::evolvePopulation
 * Se encarga de hacer el crossOver y la mutacion
 *
 * @param pPopulation: La poblacion que se desea reproducir
 * @return La totalmente nueva poblacion que se genera a partir de la reproduccion
 */


Population& Evolution:: evolvePopulation(Population &pPopulation)
{

    for (int i =0;i<((Constants::getInstance()->MAXPOPULATION)*porcentajeNatalidad);i++)
    {
        //std::cout<<"interacion: "<<i<<endl;
        Individuals* FatherA = fathersSelection(pPopulation);

        Individuals* FatherB = fathersSelection(pPopulation);
        while(FatherA->getId()==FatherB->getId()){
            FatherB = fathersSelection(pPopulation);}

        lista<Individuals>* newIndividualsList = CrossOver(*FatherA, *FatherB);


        pPopulation.insertIndividualList(newIndividualsList->getElemento(primerElemento));
        pPopulation.upPopulation();
        pPopulation.insertIndividualList(newIndividualsList->getElemento(segundoElemento));
        pPopulation.upPopulation();
    }


    for(int i =cero;i < pPopulation.getPopulationSize();i++)
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
    Individuals* fathers[porcentajePadres];

    int j=cero;
    int i=cero;
    int redondeo=round(((*(pPopulation.getIndividualbyIndex(primerElemento)->getFitness())+floatCero)/totalFitness)*cien);
    while(i<porcentajePadres){



        if((redondeo)==i){

            if(j!=(pPopulation.getPopulationSize()-1)){
            j++;
            }
            if(i<pPopulation.getPopulationSize()){
            redondeo=redondeo+round(((*(pPopulation.getIndividualbyIndex(j)->getFitness())+floatCero)/totalFitness)*cien);
            }
        }
        fathers[i]=pPopulation.getIndividualbyIndex(j);
        i++;
     }

    int ran=_random->getRandom(porcentajePadres-1);
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
        if (_random->randRange(floatCero,maxMutation) <= _mutationRate)
        {

           pIndividual->getGenes()->Flip(_random->getRandom(maxCantidadBits));
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
    BitVector* genesIndividualA = new BitVector(Constants::SKILLSQUANTITY);
    *genesIndividualA=*(pFatherA.getGenes());
    BitVector* genesIndividualB = new BitVector(Constants::SKILLSQUANTITY);
     *genesIndividualB=*(pFatherB.getGenes());

    BitVector* tmpGenesIndividualA =  new BitVector(Constants::SKILLSQUANTITY);
    *tmpGenesIndividualA=*(pFatherA.getGenes());
    BitVector* tmpGenesIndividualB = new BitVector(Constants::SKILLSQUANTITY);
    *tmpGenesIndividualB=*(pFatherB.getGenes());


    for (int Indice = cero; Indice < Constants::SKILLSQUANTITY ; Indice++)
    {
        //int tmpPuntoCruce = rand()%cantidadBits;
        int tmpPuntoCruce = _random->getRandom(cantidadBits);
        u_int8_t tmpMask = (char) Mask;
        u_int8_t maskA = (tmpMask << tmpPuntoCruce);
        u_int8_t maskB = ~(maskA);

        genesIndividualA->andOperator(Indice,maskB);
        genesIndividualB->andOperator(Indice,maskA);
        genesIndividualA->orOperator(Indice,genesIndividualB->getByIndex(Indice));


        tmpGenesIndividualA->andOperator(Indice,maskA);
        tmpGenesIndividualB->andOperator(Indice,maskB);
        tmpGenesIndividualA->orOperator(Indice,tmpGenesIndividualB->getByIndex(Indice));

    }

    Individuals* newIndividualA = new Individuals();
    newIndividualA->setGene(*genesIndividualA);
    newIndividualA->setFathers(pFatherA.getId(),pFatherB.getId());
    Individuals* newIndividualB = new Individuals();
    newIndividualB->setGene(*tmpGenesIndividualA);
    newIndividualB->setFathers(pFatherA.getId(),pFatherB.getId());

    lista<Individuals>* list= new lista<Individuals>();
    list->agregar(newIndividualA,primerElemento);
    list->agregar(newIndividualB,primerElemento);


    return list;
}


