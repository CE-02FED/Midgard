#include "Individuals.h"



Individuals::Individuals()
{
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    _Genes = new BitVector(cantidadCualidades);
    this->createIndividual();
    this->_Fitness=0;

}

Individuals::Individuals(int pID)
{
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    _Genes = new BitVector(cantidadCualidades);
    this->_ID = pID;
    this->createIndividual();
    this->_Fitness=0;
}

void Individuals::setIndividualID(int pID)
{
    this->_ID = pID;
}

int Individuals::getIndividualID()
{
    return this->_ID;
}


void Individuals::createIndividual()
{
    _Genes = generateCromosoma();

}


BitVector *Individuals::generateCromosoma()
{
    BitVector* tmpCromosoma = new BitVector(cantidadCualidades);

    for(int i =0; i< cantidadCualidades; i++)
    {
       int Skill = rand()%256;

       tmpCromosoma->insertByIndex(i,Skill); // se agrega cualidad de derecha a izquierda
       //std::cout<< "in Generate Cromosoma skill: " << std::to_string(tmpCromosoma->getByIndex(i)) << std::endl;

    }
    return tmpCromosoma;
}

void Individuals::setGene(BitVector* pBitVector)
{
    this->_Genes = pBitVector;
}

BitVector* Individuals::getGenes()
{

    return _Genes;
}



int Individuals::getFitness() {

    if ( _Fitness== 0) {          // error con _Fitness
        _Fitness = FitnessCalculation::getFitness(this->_Genes);
    }

    return _Fitness;
}




