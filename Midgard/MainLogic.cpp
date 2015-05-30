#include "MainLogic.h"

DarkElves* MainLogic::_DarkElvesPopulation=0;
Elves* MainLogic::_ElvesPopulation=0;
//Giants* MainLogic::_GiantsPopulation=0;
Dwarves* MainLogic::_DwarvesPopulation=0;
Elves* MainLogic::_ElvesPopulation2=0;
Evolution* MainLogic::_Evolution;
int MainLogic::Age=0;
int MainLogic::EddaActual=0;
Random* MainLogic::_random;
int MainLogic::generationCount=0;

int MainLogic::contador =0;


/**
 * @brief MainLogic::MainLogic: Constructor de la clase instancia
 * todo lo necesario y corre los main threads
 */
MainLogic::MainLogic()
{

    EddaActual = EddaAntigua;
    //Poblaciones
    _DarkElvesPopulation = new DarkElves(Constants::getInstance()->MAXPOPULATION, true);
    //_GiantsPopulation = new Giants(Constants::getInstance()->MAXPOPULATION, true);
    _DwarvesPopulation = new Dwarves(Constants::getInstance()->MAXPOPULATION, true);
    _ElvesPopulation = new Elves(Constants::getInstance()->MAXPOPULATION, true);
    _ElvesPopulation2 = new Elves(Constants::getInstance()->MAXPOPULATION, true);

    //Clase para Reproducirse
    _Evolution = new Evolution();


    archivoXML = new docXML();
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

    CrazyThread* fightThread = new CrazyThread((void*)actualizaMatriz,nullptr);
    fightThread->run();

}

void MainLogic::actualizaMatriz()
{
    Vector<Population>* poblaciones = new Vector<Population>(4);
    *(*poblaciones)[0]= *_DarkElvesPopulation;
    *(*poblaciones)[1]= *_ElvesPopulation2;
    *(*poblaciones)[2]= *_ElvesPopulation;
    *(*poblaciones)[3]= *_DwarvesPopulation;

    Vector<int>* filasIniciales = new Vector<int>(4);
    *(*filasIniciales)[0] = 0;
    *(*filasIniciales)[1] = 17;
    *(*filasIniciales)[2] = 0;
    *(*filasIniciales)[3] = 17;

    Vector<int>* columnasIniciales = new Vector<int>(4);
    *(*columnasIniciales)[0] = 0;
    *(*columnasIniciales)[1] = 0;
    *(*columnasIniciales)[2] = 20;
    *(*columnasIniciales)[3] = 20;

    Vector<int>* filasFinales = new Vector<int>(4);
    *(*filasFinales)[0] = 7;
    *(*filasFinales)[1] = 24;
    *(*filasFinales)[2] = 7;
    *(*filasFinales)[3] = 24;

    Vector<int>* columnasFinales = new Vector<int>(4);
    *(*columnasFinales)[0] = 5;
    *(*columnasFinales)[1] = 5;
    *(*columnasFinales)[2] = 24;
    *(*columnasFinales)[3] = 24;
    while(true)
    {        
         anadirAMatriz(poblaciones,filasIniciales,filasFinales,columnasIniciales,columnasFinales);


                                      //Posiciones Matriz

         /*
         anadirAMatriz(_ElvesPopulation2,0,0,10,10);
         anadirAMatriz(_ElvesPopulation,14,0,23,10);
         anadirAMatriz(_DwarvesPopulation,0,12,10,23);
         anadirAMatriz(_DarkElvesPopulation,14,12,24,24);*/

    }

}


void MainLogic::anadirAMatriz(Vector<Population>* pPoblaciones,Vector<int>* pFilasIniciales, Vector<int>* pFilasFinales,
                              Vector<int>* pColumnasIniciales, Vector<int>* pColumnasFinales  )
{// VERIFICAR LIMITE POBLACION

    pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

    Vector<int>* idMatriz = new Vector<int>(cantIds);
    *(*idMatriz)[0] =4;
    *(*idMatriz)[1] =15;
    *(*idMatriz)[2] =16;
    *(*idMatriz)[3] =27;
    *(*idMatriz)[4] =28;
    *(*idMatriz)[5] =39;
    *(*idMatriz)[6] =40;
    *(*idMatriz)[7] =51;

    for(int j=0; j< cantVectores;j++)
    {
        for(int i=0; i<limiteFiguras; i++)
        {
        pthread_mutex_lock(&mutex);
        _random->start();

        int posicionImatriz = _random->randRange( *(*pFilasIniciales)[j],*(*pFilasFinales)[j]);
        int posicionJmatriz =  _random->randRange(*(*pColumnasIniciales)[j],*(*pColumnasFinales)[j]);

        if(i < (*pPoblaciones)[j]->getPopulationSize())
        {
            int idFigura = _random->randRange(*(*idMatriz)[j+j],*(*idMatriz)[j+j+1]);
            Individuals* individualMatriz = (*pPoblaciones)[j]->getIndividualList()->getElemento(i);
            individualMatriz->setFigureID(idFigura);
            Map::getInstance()->anadirObjeto(posicionImatriz,posicionJmatriz,individualMatriz,idFigura);
        }
        pthread_mutex_unlock(&mutex);
        usleep(100);
        }
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
    while(generationCount!= Constants::getInstance()->GENERATIONS)
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

void MainLogic::iniciarFight()
{
        pthread_mutex_lock(&mutex);
        Vector<int>* posiblesLuchadores = new Vector<int>(4,2);
        int posicionIRaza1 = _random->randRange(1,10);
        int posicionJRaza1 = _random->randRange(1,7);

        int posicionIRaza2 = _random->randRange(17,23);
        int posicionJRaza2 = _random->randRange(1,7);

        int posicionIRaza3 = _random->randRange(17,10);
        int posicionJRaza3 = _random->randRange(19,23);

        int posicionIRaza4 = _random->randRange(17,23);
        int posicionJRaza4 = _random->randRange(19,23);

        Map::getInstance()->getObjectMatriz()[posicionIRaza1][posicionJRaza1]->findPath(8,0,12,0);
        Map::getInstance()->getObjectMatriz()[posicionIRaza2][posicionJRaza2]->findPath(18,0,13,0);
        Map::getInstance()->getObjectMatriz()[posicionIRaza3][posicionJRaza3]->findPath(8,20,12,23);
        Map::getInstance()->getObjectMatriz()[posicionIRaza4][posicionJRaza4]->findPath(18,20,13,23);
        pthread_mutex_unlock(&mutex);

    }

Vector<int>* MainLogic::getParents(int* pRaza, int* pIndividualID)
{
    contador++;
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


    while (generationCount != Constants::getInstance()->GENERATIONS)
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
