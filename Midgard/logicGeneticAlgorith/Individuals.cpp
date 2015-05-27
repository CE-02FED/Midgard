#include "Individuals.h"



Individuals::Individuals()
{
    _random = new Random();
    static int generadorID=cero;
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    _Genes = new BitVector(cantidadCualidades);
    this->_ID=generadorID++;
    this->createIndividual();
    this->_Fitness=cero;
}

Individuals::Individuals(int pID)
{
    _random = new Random();
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    _Genes = new BitVector(cantidadCualidades);
    this->_ID = pID;
    this->createIndividual();
    this->_Fitness=cero;
}
int Individuals::calculateFitness(BitVector* pIndividualGenes) // VERIFICAR BIEN
{

    int tmpFitness =cero;

    for(int i=cero; i< Constants::SKILLSQUANTITY; i++)
    {

        u_int8_t skillValue = (pIndividualGenes->getByIndex(i));

        tmpFitness+= skillValue;
    }
    return tmpFitness;
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
    generateCromosoma();

}

int Individuals::getId(){
    return _ID;
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
void Individuals::generateCromosoma()
{
    BitVector* tmpCromosoma = new BitVector(cantidadCualidades);

    for(int i =cero; i< cantidadCualidades; i++)
    {
       int Skill = _random->getRandom(maxSkill+1);

       tmpCromosoma->insertByIndex(i,Skill); // se agrega cualidad de derecha a izquierda
       //std::cout<< "in Generate Cromosoma skill: " << std::to_string(tmpCromosoma->getByIndex(i)) << std::endl;

    }
   this->_Genes=tmpCromosoma;
}

void Individuals::setGene(BitVector pBitVector)
{
    *(this->_Genes) = pBitVector;
}

BitVector* Individuals::getGenes()
{

    return _Genes;
}



int* Individuals::getFitness() {

    if ( _Fitness== cero) {          // error con _Fitness
         _Fitness = this->calculateFitness(_Genes);
    }

    return &_Fitness;
}

void Individuals::isMyBirthDay()
{
    this->_Age++;
}

void Individuals::setFathers(int pIDFather, int pIDMother)
{
    this->_FatherID = pIDFather;
    this->_MotherID = pIDMother;
}

int Individuals::getPadre()
{
    return this->_FatherID;
}

int Individuals::getMadre()
{
    return this->_MotherID;
}



