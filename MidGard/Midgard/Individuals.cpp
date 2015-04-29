#include "Individuals.h"


Individuals::Individuals()
{
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    genes = new BitVector(cantidadCualidades);
}

Individuals::Individuals(int pID)
{
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    genes = new BitVector(cantidadCualidades);
    this->_ID = pID;
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
    BitVector* Cromosoma = new BitVector(cantidadCualidades);

    Cromosoma = generateCromosoma();
}


BitVector *Individuals::generateCromosoma()
{
    BitVector* tmpCromosoma = new BitVector(cantidadCualidades);

    for(int i =0; i< cantidadCualidades; i++)
    {
       int Skill = rand()%255;
       int tmpGen = DecToBn(Skill,1);
       tmpCromosoma->insertByIndex(i,tmpGen); // se agrega cualidad de derecha a izquierda
    }
    return tmpCromosoma;
}

void Individuals::setGene(BitVector* pBitVector)
{
    this->genes = pBitVector;
}

BitVector* Individuals::getGenes()
{

    return genes;
}



int Individuals::getFitness() {

    if ( _Fitness== 0) {          // error con _Fitness

        cout << "fitness individual" << endl;
        _Fitness = FitnessCalculation::getFitness(this);
    }
    return _Fitness;
}

size_t Individuals::DecToBn(int pNum, int exp)
{
    if ( pNum == 0 ) return 0;
    if ( pNum == 1 ) return 1;

    if ( pNum % 2 == 0 )
       return 0 + DecToBn(pNum / 2,exp*10) ;
    else
        return 1 + DecToBn(pNum / 2, exp*10);

}


