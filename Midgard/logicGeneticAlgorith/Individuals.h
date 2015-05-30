#ifndef INDIVIDUALS_H
#define INDIVIDUALS_H
//#include "FitnessCalculation.h"
#include "../res/BitVector.h"
#include "../res/Constants.h"
#include "../res/Random.h"
#include "../res/vector.h"
#include "../logicGame/Map.h"
#include "../logicGame/pathfinding.h"


#define maxSkill 255
#define cero 0
#define cantPosiciones
//class FitnessCalculation;
class Pathfinding;
class Individuals
{
protected:
    int _Fitness=0;
    Random* _random;
    int _ID;
    int _Age=0;
    int _MotherID = -1; // si es < 0 significa que estos son la primera generacion
    int _FatherID = -1;    
    BitVector* _Genes;
    int cantidadCualidades;    
    bool veriBase(size_t pNum);
    Pathfinding* _encontrarCamino;
    static int figuraID;
    static bool termino;
    static Vector<int>* _movimiento;




public:
    int getId();
    int calculateFitness(BitVector* pIndividualGenes);
    Individuals();
    Individuals(int pID);
    int getIndividualID();
    void setIndividualID(int pID);
    void setFathers(int pIDFather, int pIDMother);
    int getPadre();
    int getMadre();



    void generateCromosoma();
    void createIndividual();
    void setGene(BitVector pBitVector);
    BitVector* getGenes();
    int* getFitness();

    int getCantidadCualidades();
    void isMyBirthDay();

    Vector<int> *findPath(int posicionInicialI, int posicionInicialJ, int posicionFinalI, int posicionFinalJ);
    static void *moverIndividuo(void *pParametro);
    static void setFigureID(int pNumber);
    bool getTermino();
    void setTermino(bool value);
};

#endif // INDIVIDUALS_H
