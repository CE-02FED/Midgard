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


/**

 * @brief Individuals::generateCromosoma: Genera el cromosoma del individuo
 *
 * La casilla Indice =0 del array representará la Vida
 * La casilla Indice =1 del array representará la Inteligencia
 * La casilla Indice =2 del array representará el Ataque
 * La casilla Indice =3 del array representará la Defensa
 * La casilla Indice =4 del array representará la Velocidad de ataque
 * La casilla Indice =5 del array representará la Magia
 * La casilla Indice =6 del array representará la Energia Vital
 * La casilla Indice =7 del array representará la Supersticion
 * La casilla Indice =8 del array representará el Sacrificio
 * La casilla Indice =9 del array representará la Invocacion
 *
 * @return El BitVector Con el cromosoma de dicho individuo
 */
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

void Individuals::setFathers(int pIDFather, int pIDMother)
{
    this->_FatherID = pIDFather;
    this->_MotherID = pIDMother;
}

int Individuals::getFathers()
{
    int tmpFathersArray[] = {this->_FatherID, this->_MotherID};
    return  *tmpFathersArray;
}



