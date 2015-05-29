#include "GameIndividual.h"

GameIndividual::GameIndividual(int pCualidades[])
{
    GameIndividual::createIndividual(pCualidades);
}
void GameIndividual::createIndividual(int pCualidades[])
{
    this->setGene(*(GameIndividual::generateCromosoma(pCualidades)));
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
 * @return El BitVector* Con el cromosoma de dicho individuo
 */
BitVector* GameIndividual::generateCromosoma(int pCualidades[])
{
    BitVector* tmpCromosoma = new BitVector(cantidadCualidades);

    for(int i =0; i< this->cantidadCualidades; i++)
    {
        if (pCualidades[i] == PrioridadAlta)
        {
            int Skill = _random->randRange(MidValue,maxSkill);
            tmpCromosoma->insertByIndex(i,Skill);

        }
        if (pCualidades[i]== PrioridadBaja)
        {
            int Skill = _random->randRange(lowestValue,MidValue);
            tmpCromosoma->insertByIndex(i,Skill);
        }
        else
        {
            int Skill = _random->getRandom(maxSkill);
            tmpCromosoma->insertByIndex(i,Skill);
        }
        //std::cout<<"Skill " << i<<": "<<to_string(tmpCromosoma->getByIndex(i))<<std::endl;
    }
    *_Genes=*tmpCromosoma;
    return _Genes;
}

void GameIndividual::setFathers(int pIDFather, int pIDMother)
{
    this->_FatherID = pIDFather;
    this->_MotherID = pIDMother;
}

int GameIndividual::getFathers()
{
    int tmpFathersArray[] = {this->_FatherID, this->_MotherID};
    return  *tmpFathersArray;
}

string GameIndividual::findPath(Vector<int> pMatrizJuego, int posicionInicialI,int posicionInicialJ,
                                int posicionFinalI,int posicionFinalJ)
{
    _encontrarCamino = new Pathfinding((Vector<short>*)&pMatrizJuego);



    return _encontrarCamino->find( posicionInicialI, posicionInicialJ, posicionFinalI, posicionFinalJ);

}








