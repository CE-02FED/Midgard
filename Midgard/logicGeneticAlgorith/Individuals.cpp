#include "Individuals.h"

Vector<int>* Individuals::_movimiento;
//Pathfinding* Individuals::_encontrarCamino;

bool Individuals::termino =false;
int Individuals::figuraID=1;



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


bool Individuals::getTermino()
{
    return termino;
}

void Individuals::setTermino(bool value)
{
    termino = value;
}



Vector<int>* Individuals::getPosicionIndividual()
{
    Vector<int>* posiciones = new Vector<int>(2);
    *(*posiciones)[0] =_posicionXmatriz;
    *(*posiciones)[1] =_posicionYmatriz;
    return posiciones;
}

void Individuals::setPosicionIndividual(int pPosicionX, int pPosicionY)
{
    _posicionXmatriz = pPosicionX;
    _posicionYmatriz = pPosicionY;
}

void Individuals::setFitness(int pFitness)
{
    _Fitness = pFitness;
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

Vector<int>* Individuals::findPath( int posicionInicialI,int posicionInicialJ,
                                int posicionFinalI,int posicionFinalJ)
{
    cout << "entre findPath"<<endl;

    _encontrarCamino = new Pathfinding();

    _movimiento = _encontrarCamino->calcularRuta(posicionInicialI,posicionInicialJ,posicionFinalI,posicionFinalJ);

    return _movimiento;
}

void* Individuals::moverIndividuo(void* pParametro)
{
    Vector<int>* d = (Vector<int>*) pParametro;
    cout <<"pum pum pra pra pra pra" << endl;

    for(int i =0; i< d->getHeight(); i++)
    {
        cout << "entro a esta porqueria"<<endl;
        Map::anadirObjeto((*d)[i][0],(*d)[i][1],new Individuals(),figuraID);
        if (i>1)
        {
        Map::anadirObjeto((*d)[i-1][0],(*d)[i-1][1],new Individuals(),0);
        }
        sleep(2);
    }
    cout << "true"<< endl;
    termino = true;
}

void Individuals::setFigureID(int pNumber)
{
    figuraID = pNumber;
}

