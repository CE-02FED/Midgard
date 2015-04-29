#include "Individuals.h"


Individuals::Individuals()
{

    this->cantidadCualidades = Constants::_SkillsQuantity;
    genes = new BitVector(cantidadCualidades);


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

BitVector* Individuals::getGenes(){ cout << genes->Size() << endl;return this->genes;}



int Individuals::getFitness() {
    cout << "entro a GetFitness" << endl;
    int d =0;
    if ( d== 0) {                                  // error con _Fitness
        cout << "tata" << endl;
        d = FitnessCalculation::getFitness(this);
        cout << "hol"<< endl;
    }
    cout << "_PopulationSize" << endl;

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


