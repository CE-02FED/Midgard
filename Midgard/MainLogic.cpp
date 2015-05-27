#include "MainLogic.h"

DarkElves* MainLogic::_DarkElvesPopulation=0;
Elves* MainLogic::_ElvesPopulation;
Giants* MainLogic::_GiantsPopulation;
Dwarves* MainLogic::_DwarvesPopulation;
Evolution* MainLogic::_Evolution;
int MainLogic::Age=0;
int MainLogic::EddaActual=0;
Random* MainLogic::_random=0;

MainLogic::MainLogic()
{
    _DarkElvesPopulation = new DarkElves(50, true);
    _GiantsPopulation = new Giants(50, true);
    _DwarvesPopulation = new Dwarves(50, true);
    _ElvesPopulation = new Elves(50, true);
    _Evolution = new Evolution();


    archivoXML = new docXML();
    matriz = new Vector<int> (3,3);
    matriz->llenarMatriz(0);
    (*matriz)[0][0]=3;
    (*matriz)[1][1]=4;
    (*matriz)[1][2]=2;
    _random = new Random();

    runLogic()  ;

    //matriz = initMatriz();
}

void MainLogic::runLogic()
{
    EddaActual = EddaAntigua;
    CrazyThread* runThread = new CrazyThread((void*)evolution, nullptr);
    runThread->run();

    CrazyThread* ageThread = new CrazyThread((void*)HappyNewYear, nullptr);
    ageThread->run();

    CrazyThread* mainThread = new CrazyThread((void*)mainGame, nullptr);
    mainThread->run();      
}

void MainLogic::mainGame()
{
    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
    bool EddaCaracteristicas = true;
    while(EddaActual!= AtardecerDioses)
    {
        pthread_mutex_lock(&mutex);
        if (EddaActual ==EddaAntigua)
        {
            EddaCaracteristicas = EddaAntiguaMethod(EddaCaracteristicas);

        }
        if(EddaActual == EddaReligiosa)
        {
            EddaCaracteristicas = EddaReligiosaMethod(EddaCaracteristicas);
        }
        if(EddaActual == EddaCienciaTecnologia)
        {
            EddaCaracteristicas = EddaCienciaTecnologiaMethod(EddaCaracteristicas);
        }
        if(EddaActual == EddaSupremacia)
        {
            EddaCaracteristicas = EddaSupremaciaMethod(EddaCaracteristicas);
        }
        if(EddaActual == EddaPazMundial)
        {
            EddaPazMundialMethod();
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);

    }
}


void MainLogic::indidvidualFight()
{
    for(int i =0; i< matriz->getHeight(); i++)
    {
        for(int j=0; j< matriz->getWidth();j++)
        {
            if(matriz[i][j]);
        }

    }

}












Vector<int>* MainLogic::getParents(int* pRaza, int* pIndividualID)
{
    /*Vector<int>* Family = new Vector<int>(3);
    switch (*pRaza) {
    case darkElves:
        Family[0] = _DarkElvesPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _DarkElvesPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _DarkElvesPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;

    case elves:
        Family[0] = _ElvesPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _ElvesPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _ElvesPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;

    case dwarves:
        Family[0] = _DwarvesPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _DwarvesPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _DwarvesPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;
    case giants:
        Family[0] = _GiantsPopulation->getIndividualbyIndex(pIndividualID)->getPadre();
        Family[1] = _GiantsPopulation->getIndividualbyIndex(pIndividualID)->getMadre();
        Family[2] = _GiantsPopulation->getIndividualbyIndex(pIndividualID)->getFitness();
        break;
    default:
        break;
    }*/
    //return Family;
    Vector<int>* Family2 = new Vector<int>(3);
    Family2->llenarMatriz(0);
    *(*Family2)[0] = 1;
    *(*Family2)[1] = 2;
    *(*Family2)[2] = 3;
    return Family2;
}

Vector<int>* MainLogic::getMap()
{        
    return matriz;
}

void MainLogic::fight(Individuals* individual1, Individuals* individual2){
    int sumaFit= *(individual1->getFitness())+*(individual2->getFitness());
    Individuals* probabilidad[cien];
    int redondeo=round(((*(individual1->getFitness())+floatCero)/sumaFit)*cien);

    for(int i=cero;i<cien;i++){
        if(redondeo<=i){
            probabilidad[i]=individual1;
        }
        else{
            probabilidad[i]=individual2;
        }

    }

    int ran=_random->getRandom(cien);
    Individuals* survivor= probabilidad[ran];
    if(survivor->getId()==individual1->getId()){

    _GiantsPopulation->deleteIndividualList(individual2);
    _DarkElvesPopulation->deleteIndividualList(individual2);
    _DwarvesPopulation->deleteIndividualList(individual2);
    _ElvesPopulation->deleteIndividualList(individual2);
    }
    else{
        _GiantsPopulation->deleteIndividualList(individual1);
        _DarkElvesPopulation->deleteIndividualList(individual1);
        _DwarvesPopulation->deleteIndividualList(individual1);
        _ElvesPopulation->deleteIndividualList(individual1);
    }
}

void MainLogic::HappyNewYear()
{
    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
    while(EddaActual !=AtardecerDioses)
    {
        pthread_mutex_lock(&mutex);
        Age++;
        _DarkElvesPopulation->isPopBirthDay();
        _ElvesPopulation->isPopBirthDay();
        _GiantsPopulation->isPopBirthDay();
        _DwarvesPopulation->isPopBirthDay();
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }
}




void MainLogic::evolution()
{
    srand(time(0));


    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;    

    // Evolve our population until we reach an optimum solution
    int generationCount = 0;
    while (generationCount <Constants::getInstance()->GENERATIONS)
    {
        pthread_mutex_lock(&mutex);
        generationCount++;
        _DarkElvesPopulation = (DarkElves*)&(_Evolution->evolvePopulation(*_DarkElvesPopulation));
        _GiantsPopulation = (Giants*)&_Evolution->evolvePopulation(*_GiantsPopulation);
        _DwarvesPopulation = ((Dwarves*)&_Evolution->evolvePopulation(*_DwarvesPopulation));
        _ElvesPopulation = (Elves*)&_Evolution->evolvePopulation(*_ElvesPopulation);


        pthread_mutex_unlock(&mutex);
        usleep(1000);
    }

}

/**
 * @brief MainLogic::initMatriz: Lee el archivo xml la casilla de la matriz y la retorna
 * @return la matriz contenida en el XML
 */
Vector<int> *MainLogic::initMatriz()
{
    int Height = archivoXML->getMatrizHeight();
    int Width = archivoXML->getMatrizWidth();
    Vector<int>* newMatriz = new Vector<int>(Width,Height);
    string tmpMap = archivoXML->getMatriz();
        string numero = "";

        int index = 0, jindex = 0;
        for (int i = 0; i < tmpMap.length(); i++) {
            if (index >= Height) {
                break;
            }
            if (jindex >= Width) {
                jindex = 0;
                index++;
            }
            if (tmpMap[i] == '#') {
                (*newMatriz)[index][jindex] = stoi(numero);
                jindex++;
                numero = "";
            }
            else {
                numero += tmpMap[i];
            }
        }
  return newMatriz;

}

bool MainLogic::EddaAntiguaMethod(bool pImprovePopulation)
{
    if(pImprovePopulation)
    {
    Vector<int>* newSkills= new Vector<int>(10);

    *(*newSkills)[vida]= despreciable;
    *(*newSkills)[inteligencia]= despreciable;
    *(*newSkills)[ataque]= alto;
    *(*newSkills)[defensa]= alto;
    *(*newSkills)[velAtaque]= despreciable;
    *(*newSkills)[magia]= despreciable;
    *(*newSkills)[energiaVital]= despreciable;
    *(*newSkills)[supersticion]= despreciable;
    *(*newSkills)[invocacion]= despreciable;


    _DarkElvesPopulation->CambioEdda(*newSkills);
    _ElvesPopulation->CambioEdda(*newSkills);
    _GiantsPopulation->CambioEdda(*newSkills);
    _DwarvesPopulation->CambioEdda(*newSkills);
    }

    if(_DarkElvesPopulation->getFittest()->getGenes()->getByIndex(supersticion)>= 70)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation->getFittest()->getGenes()->getByIndex(supersticion)>= 70)
    {
        EddaActual++;
        return true;
    }
    if(_GiantsPopulation->getFittest()->getGenes()->getByIndex(supersticion)>= 70)
    {
        EddaActual++;
        return true;
    }
    if(_DwarvesPopulation->getFittest()->getGenes()->getByIndex(supersticion)>= 70)
    {
        EddaActual++;
        return true;
    }
    else return false;
}

bool MainLogic::EddaReligiosaMethod( bool pImprovePopulation)
{
    if(pImprovePopulation)
    {
    Vector<int>* newSkills= new Vector<int>(10);

    *(*newSkills)[vida]= alto;
    *(*newSkills)[inteligencia]= despreciable;
    *(*newSkills)[ataque]= alto;
    *(*newSkills)[defensa]= alto;
    *(*newSkills)[velAtaque]= alto;
    *(*newSkills)[magia]= alto;
    *(*newSkills)[energiaVital]= alto;
    *(*newSkills)[supersticion]= alto;
    *(*newSkills)[invocacion]= alto;

    _DarkElvesPopulation->CambioEdda(*newSkills);
    _ElvesPopulation->CambioEdda(*newSkills);
    _GiantsPopulation->CambioEdda(*newSkills);
    _DwarvesPopulation->CambioEdda(*newSkills);
    }

    if(_DarkElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 100)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 100)
    {
        EddaActual++;
        return true;
    }
    if(_GiantsPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 100)
    {
        EddaActual++;
        return true;
    }
    if(_DwarvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 100)
    {
        EddaActual++;
        return true;
    }
    else return false;
}

bool MainLogic::EddaCienciaTecnologiaMethod(bool pImprovePopulation)
{
    if(pImprovePopulation)
    {
    Vector<int>* newSkills= new Vector<int>(10);

    *(*newSkills)[vida]= noCambia;
    *(*newSkills)[inteligencia]= alto;
    *(*newSkills)[ataque]= alto;
    *(*newSkills)[defensa]= alto;
    *(*newSkills)[velAtaque]= noCambia;
    *(*newSkills)[magia]= noCambia;
    *(*newSkills)[energiaVital]= noCambia;
    *(*newSkills)[supersticion]= noCambia;
    *(*newSkills)[invocacion]= noCambia;

    _DarkElvesPopulation->CambioEdda(*newSkills);
    _ElvesPopulation->CambioEdda(*newSkills);
    _GiantsPopulation->CambioEdda(*newSkills);
    _DwarvesPopulation->CambioEdda(*newSkills);
    }

    if(_DarkElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 140)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 140)
    {
        EddaActual++;
        return true;
    }
    if(_GiantsPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 140)
    {
        EddaActual++;
        return true;
    }
    if(_DwarvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= 140)
    {
        EddaActual++;
        return true;
    }
    else return false;
}

bool MainLogic::EddaSupremaciaMethod(bool pImprovePopulation)
{
    if(pImprovePopulation)
    {
    Vector<int>* newSkills= new Vector<int>(10);

    *(*newSkills)[vida]= alto;
    *(*newSkills)[inteligencia]= alto;
    *(*newSkills)[ataque]= alto;
    *(*newSkills)[defensa]= alto;
    *(*newSkills)[velAtaque]= alto;
    *(*newSkills)[magia]= alto;
    *(*newSkills)[energiaVital]= alto;
    *(*newSkills)[supersticion]= alto;
    *(*newSkills)[invocacion]= alto;

    _DarkElvesPopulation->CambioEdda(*newSkills);
    _ElvesPopulation->CambioEdda(*newSkills);
    _GiantsPopulation->CambioEdda(*newSkills);
    _DwarvesPopulation->CambioEdda(*newSkills);
    }

    if(_DarkElvesPopulation->getFittest()->getFitness() == _DarkElvesPopulation->getFitless()->getFitness())
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation->getFittest()->getFitness() == _ElvesPopulation->getFitless()->getFitness())
    {
        EddaActual++;
        return true;
    }
    if(_GiantsPopulation->getFittest()->getFitness() == _GiantsPopulation->getFitless()->getFitness())
    {
        EddaActual++;
        return true;
    }
    if(_DwarvesPopulation->getFittest()->getFitness()== _DarkElvesPopulation->getFitless()->getFitness())
    {
        EddaActual++;
        return true;
    }
    else return false;
}

void MainLogic::EddaPazMundialMethod()
{
    Population* unionDePueblos = new Population();


    for(int i =0; i<_DarkElvesPopulation->getIndividualList()->getNumEle();i++)
    {
        unionDePueblos->insertIndividualList(_DarkElvesPopulation->getIndividualList()->getElemento(i));

    }
    for(int i =0; i<_DwarvesPopulation->getIndividualList()->getNumEle();i++)
    {
        unionDePueblos->insertIndividualList(_DwarvesPopulation->getIndividualList()->getElemento(i));

    }
    for(int i =0; i<_GiantsPopulation->getIndividualList()->getNumEle();i++)
    {
        unionDePueblos->insertIndividualList(_GiantsPopulation->getIndividualList()->getElemento(i));

    }
    for(int i =0; i<_ElvesPopulation->getIndividualList()->getNumEle();i++)
    {
        unionDePueblos->insertIndividualList(_ElvesPopulation->getIndividualList()->getElemento(i));
    }

    return;

}
