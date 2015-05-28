#include "MainLogic.h"

DarkElves* MainLogic::_DarkElvesPopulation=0;
int MainLogic::contador=0;
Elves* MainLogic::_ElvesPopulation=0;
//Giants* MainLogic::_GiantsPopulation=0;
Dwarves* MainLogic::_DwarvesPopulation=0;
Elves* MainLogic::_ElvesPopulation2=0;
int MainLogic::generationCount=0;
Evolution* MainLogic::_Evolution;
int MainLogic::Age=0;
int MainLogic::EddaActual=0;
Random* MainLogic::_random;


/**
 * @brief MainLogic::MainLogic: Constructor de la clase instancia
 * todo lo necesario y corre los main threads
 */
MainLogic::MainLogic()
{

    EddaActual = EddaAntigua;
    //Poblaciones
    _DarkElvesPopulation = new DarkElves(50, true);
    //_GiantsPopulation = new Giants(50, true);
    _DwarvesPopulation = new Dwarves(50, true);
    _ElvesPopulation = new Elves(50, true);
    _ElvesPopulation2 = new Elves(50, true);

    //Clase para Reproducirse
    _Evolution = new Evolution();


    archivoXML = new docXML();
    /*Map::getInstance()->anadirObjeto(0,0,0,20);
    Map::getInstance()->anadirObjeto(20,20,0,10);
    Map::getInstance()->anadirObjeto(15,15,0,4);
    Map::getInstance()->anadirObjeto(11,11,0,30);
    Map::getInstance()->anadirObjeto(3,3,0,6);*/

    /*matriz = new Vector<int> (3,3);
    matriz->llenarMatriz(0);
    (*matriz)[0][0]=3;
    (*matriz)[1][1]=4;
    (*matriz)[1][2]=2;*/
    _random = new Random();

    runLogic();

    //matriz = initMatriz();
}

/**
 * @brief MainLogic::runLogic
 * Corre los main threads
 */
void MainLogic::runLogic()
{    
    CrazyThread* runThread = new CrazyThread((void*)evolution, nullptr);
    runThread->run();

    CrazyThread* ageThread = new CrazyThread((void*)HappyNewYear, nullptr);
    ageThread->run();

    CrazyThread* mainThread = new CrazyThread((void*)mainGame, nullptr);
    mainThread->run();

    CrazyThread* matrizThread = new CrazyThread((void*)actualizaMatriz,nullptr);
    matrizThread->run();

}

void MainLogic::actualizaMatriz()
{
    while(true)
    {
                                      //Posiciones Matriz
         anadirAMatriz(_ElvesPopulation2,0,0,10,10);
         anadirAMatriz(_ElvesPopulation,14,0,24,10);
         anadirAMatriz(_DwarvesPopulation,0,12,10,24);
         anadirAMatriz(_DarkElvesPopulation,14,12,24,24);
    }

}


void MainLogic::anadirAMatriz(Population* pPoblacion, int pLimiteFilaInicial, int pLimiteColumnaInicial,
                              int pLimiteFilaFinal, int pLimiteColumnaFinal )
{// VERIFICAR LIMITE POBLACION

    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

    for(int i=0; i<limiteFiguras; i++)
    {
        cout << "entro matriz" << endl;
        pthread_mutex_lock(&mutex);
        _random->start();
        int I = _random->randRange(pLimiteFilaInicial,pLimiteFilaFinal);
        int J=  _random->randRange(pLimiteColumnaInicial,pLimiteColumnaFinal);
        Map::getInstance()->anadirObjeto(I,J,pPoblacion->getIndividualList()->getElemento(i)->getId(),_random->getRandom(60));
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }


}




/**
 * @brief MainLogic::mainGame
 *
 */
void MainLogic::mainGame()
{
    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
    bool EddaCaracteristicas = true;
    while(EddaActual!= Constants::getInstance()->GENERATIONS)
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

    Vector<int>* Family = new Vector<int>(3);
    switch (*pRaza) {
    case darkElves:
        *(*Family)[0] = _DarkElvesPopulation->getIndividualbyIndex(contador)->getPadre();
        *(*Family)[1] = _DarkElvesPopulation->getIndividualbyIndex(contador)->getMadre();
        *(*Family)[2] = *_DarkElvesPopulation->getIndividualbyIndex(contador)->getFitness();
        break;

    case elves:
        *(*Family)[0] = _ElvesPopulation->getIndividualbyIndex(contador)->getPadre();
        *(*Family)[1] = _ElvesPopulation->getIndividualbyIndex(contador)->getMadre();
        *(*Family)[2] = *_ElvesPopulation->getIndividualbyIndex(contador)->getFitness();
        break;

    case dwarves:
        *(*Family)[0] = _DwarvesPopulation->getIndividualbyIndex(contador)->getPadre();
        *(*Family)[1] = _DwarvesPopulation->getIndividualbyIndex(contador)->getMadre();
        *(*Family)[2] = *_DwarvesPopulation->getIndividualbyIndex(contador)->getFitness();
        break;
    case giants:
        *(*Family)[0] = _ElvesPopulation2->getIndividualbyIndex(contador)->getPadre();
        *(*Family)[1] = _ElvesPopulation2->getIndividualbyIndex(contador)->getMadre();
        *(*Family)[2] = *_ElvesPopulation2->getIndividualbyIndex(contador)->getFitness();
        break;
    default:
        break;
    }
    //return Family;
    /*Vector<int>* Family2 = new Vector<int>(3);
    Family2->llenarMatriz(0);
    *(*Family2)[0] = 1;
    *(*Family2)[1] = 2;
    *(*Family2)[2] = 3;*/
    contador++;
    return Family;
}

Vector<int>* MainLogic::getMap()
{        
    return Map::getInstance()->getMapMatriz();
}

Vector<int> *MainLogic::getPuebloInfo(int pPueblo)
{
    Vector<int>* puebloInfo = new Vector<int>(3);

    switch (pPueblo) {
    case darkElves:
        *(*puebloInfo)[0]= *(_DarkElvesPopulation->getFittest()->getFitness());
        *(*puebloInfo)[1]= *(_DarkElvesPopulation->getFitless()->getFitness());
        *(*puebloInfo)[2]= _DarkElvesPopulation->getPopulationSize();
        break;
    case elves:
        *(*puebloInfo)[0]= *(_ElvesPopulation->getFittest()->getFitness());
        *(*puebloInfo)[1]= *(_ElvesPopulation->getFitless()->getFitness());
        *(*puebloInfo)[2]= _ElvesPopulation->getPopulationSize();

        break;
    case dwarves:
        *(*puebloInfo)[0]= *(_DwarvesPopulation->getFittest()->getFitness());
        *(*puebloInfo)[1]= *(_DwarvesPopulation->getFitless()->getFitness());
        *(*puebloInfo)[2]= _DwarvesPopulation->getPopulationSize();

        break;
    case giants:
        *(*puebloInfo)[0]= *(_ElvesPopulation2->getFittest()->getFitness());
        *(*puebloInfo)[1]= *(_ElvesPopulation2->getFitless()->getFitness());
        *(*puebloInfo)[2]= _ElvesPopulation2->getPopulationSize();
        break;
    default:
        break;
    }

    return puebloInfo;
}

void MainLogic::fight(Individuals* individual1, Individuals* individual2){
    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    int sumaFit= *(individual1->getFitness())+*(individual2->getFitness());
    std::cout<<"fitness i1 "<<*(individual1->getFitness())<<std::endl;
    std::cout<<"fitness i2 "<<*(individual2->getFitness())<<std::endl;
    std::cout<<"sumafit "<<sumaFit<<std::endl;
    Individuals* probabilidad[cien];
    int redondeo=round(((*(individual1->getFitness())+floatCero)/sumaFit)*cien);
       std::cout<<"redondeo "<<redondeo<<std::endl;
    for(int i=cero;i<cien;i++){
        if(redondeo<=i){
            probabilidad[i]=individual1;
        }
        else{
            probabilidad[i]=individual2;
        }

    }

    int ran=_random->getRandom(cien);
    std::cout<<"Random "<<ran<<std::endl;
    Individuals* survivor= probabilidad[ran];
    pthread_mutex_unlock(&mutex);
    if(survivor->getId()==individual1->getId()){

    if(_ElvesPopulation2->deleteIndividualList(individual2)){
        _ElvesPopulation2->downPopulation();
    }
    if(_DarkElvesPopulation->deleteIndividualList(individual2)){
        _DarkElvesPopulation->downPopulation();
    }
    if(_DwarvesPopulation->deleteIndividualList(individual2)){
        _DwarvesPopulation->downPopulation();
    }
    if(_ElvesPopulation->deleteIndividualList(individual2)){
        _ElvesPopulation->downPopulation();
    }
    }
    else{
        if(_ElvesPopulation2->deleteIndividualList(individual1)){
            _ElvesPopulation2->downPopulation();
        }
        if(_DarkElvesPopulation->deleteIndividualList(individual1)){
            _DarkElvesPopulation->downPopulation();
        }
        if(_DwarvesPopulation->deleteIndividualList(individual1)){
            _DwarvesPopulation->downPopulation();
        }
        if(_ElvesPopulation->deleteIndividualList(individual1)){
            _ElvesPopulation->downPopulation();
        }
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
        _ElvesPopulation2->isPopBirthDay();
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


    while (generationCount < Constants::getInstance()->GENERATIONS)
    {

        pthread_mutex_lock(&mutex);        
        generationCount++;
        _DarkElvesPopulation = (DarkElves*)&(_Evolution->evolvePopulation(*_DarkElvesPopulation));        
        //_GiantsPopulation = (Giants*)&_Evolution->evolvePopulation(*_GiantsPopulation);
        _DwarvesPopulation = ((Dwarves*)&_Evolution->evolvePopulation(*_DwarvesPopulation));
        _ElvesPopulation = (Elves*)&_Evolution->evolvePopulation(*_ElvesPopulation);
        _ElvesPopulation2 = (Elves*)&_Evolution->evolvePopulation(*_ElvesPopulation);        
        pthread_mutex_unlock(&mutex);
        sleep(1);
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
    _ElvesPopulation2->CambioEdda(*newSkills);
    _DwarvesPopulation->CambioEdda(*newSkills);
    }

    if(_DarkElvesPopulation->getFittest()->getGenes()->getByIndex(supersticion)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation->getFittest()->getGenes()->getByIndex(supersticion)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation2->getFittest()->getGenes()->getByIndex(supersticion)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_DwarvesPopulation->getFittest()->getGenes()->getByIndex(supersticion)>= limiteEdda)
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
    _ElvesPopulation2->CambioEdda(*newSkills);
    _DwarvesPopulation->CambioEdda(*newSkills);
    }

    if(_DarkElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation2->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_DwarvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
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
    _ElvesPopulation2->CambioEdda(*newSkills);
    _DwarvesPopulation->CambioEdda(*newSkills);
    }

    if(_DarkElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_ElvesPopulation2->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
    {
        EddaActual++;
        return true;
    }
    if(_DwarvesPopulation->getFittest()->getGenes()->getByIndex(inteligencia)>= limiteEdda)
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
    _ElvesPopulation2->CambioEdda(*newSkills);
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
    if(_ElvesPopulation2->getFittest()->getFitness() == _ElvesPopulation2->getFitless()->getFitness())
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
    for(int i =0; i<_ElvesPopulation2->getIndividualList()->getNumEle();i++)
    {
        unionDePueblos->insertIndividualList(_ElvesPopulation2->getIndividualList()->getElemento(i));

    }
    for(int i =0; i<_ElvesPopulation->getIndividualList()->getNumEle();i++)
    {
        unionDePueblos->insertIndividualList(_ElvesPopulation->getIndividualList()->getElemento(i));
    }

    return;

}
