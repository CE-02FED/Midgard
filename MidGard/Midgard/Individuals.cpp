#include "Individuals.h"


Individuals::Individuals()
{
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    genes = new BitVector(cantidadCualidades);
    _ID = (int*) malloc(sizeof(int));
    *_ID = 0;
     _Fitness = (int*) malloc(sizeof(int));
     *_Fitness = 0;
}

Individuals::Individuals(int pID)
{
    this->cantidadCualidades = Constants::SKILLSQUANTITY;
    genes = new BitVector(cantidadCualidades);
    _ID = (int*) malloc(sizeof(int));
    *_ID = pID;
    _Fitness = (int*) malloc(sizeof(int));
    *_Fitness = 0;
}

void Individuals::setIndividualID(int pID)
{
    *_ID = pID;
}

int Individuals::getIndividualID()
{
    return *_ID;
}



void Individuals::createIndividual()
{
    BitVector* Cromosoma = new BitVector(cantidadCualidades);

    Cromosoma = generateCromosoma();
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

    if (*_Fitness== 0) {          // error con _Fitness

        cout << "fitness individual" << endl;
        *_Fitness = FitnessCalculation::getFitness(this);
    }
    return *_Fitness;
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


