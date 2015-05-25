#include "Scene.h"

QGraphicsScene* Scene:: scene;
//Scene* Scene::_scene = 0;
Vector<int>* Scene::_guiMapActual;
Vector<int>* Scene::_guiMapPrevious;
ObjectsGui* Scene::_objectGui;
int Scene::_IdIndividual  = 0;
int Scene::previousCoordX=0;
int Scene::previousCoordY=0;
int Scene::actualCoordX=0;
int Scene::actualCoordY=0;

Scene::Scene() : QGraphicsView()
{
    playScene = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    for(int i = 0; i < 5; i++)
    {
        playlist->addMedia(QUrl::fromLocalFile("/home/fabian/Escritorio/medieval2.mp3"));
        playlist->addMedia(QUrl::fromLocalFile("/home/fabian/Escritorio/medieval.mp3"));

    }
    playlist->setCurrentIndex(1);

    playScene->setPlaylist(playlist);
    playScene->setVolume(15);
    playScene->play();

    _guiMapActual = new Vector<int>(WIDTH_MAP,HEIGHT_MAP);
    _guiMapPrevious = new Vector<int>(WIDTH_MAP,HEIGHT_MAP);
    _guiMapPrevious->llenarMatriz(0);
    scene = new QGraphicsScene(0,0,WIDTH_POS,HEIGHT_POS);
    QPixmap _background("/home/fabian/Escritorio/imagenes GUI/grass.png");
    setScene(scene);
    scene->setBackgroundBrush(_background.scaled(WIDTH_SCENE,HEIGHT_SCENE,Qt::IgnoreAspectRatio,
                                                 Qt::SmoothTransformation));

    MyThread* _threadGui = new MyThread((void*)paintMap,nullptr);
    cout << "antes del run" << endl;
    _threadGui->run();


}

Vector<int>* Scene::getMapActual()
{
    return _guiMapActual;
}


void Scene::setMapActual(Vector<int> *pMatrixActual)
{

    *_guiMapActual = *pMatrixActual;
}

Vector<int> *Scene::getMapPrevious()
{
    return _guiMapPrevious;
}

bool Scene::verificaMapPrevious()
{
    int index = 0;
    for (int i=0 ; i < _guiMapPrevious->getHeight() ; i++)
    {
        for (int j=0 ; j < _guiMapPrevious->getWidth() ; j++)
        {
            if (index == MAP_POSITIONS)
                return true;
            else if (_guiMapPrevious[i][j] == 0)
                index++;
            else
                return false;
        }
    }
}

void Scene::leftWalk(int pIndexi, int pIndexj, ObjectsGui *pGuiObject)
{
    pGuiObject->setId(_IdIndividual);
    _IdIndividual++;
    previousCoordX = pIndexi * PIXELS_POS;
    previousCoordY = pIndexj * PIXELS_POS;
    actualCoordX = (pIndexi-1) * PIXELS_POS;
    _objectGui = pGuiObject;
    MyThread* _walkThread = new MyThread((void*)updateLeftPos,nullptr);
    _walkThread->run();
}




void Scene::rightWalk(int pIndexi, int pIndexj, ObjectsGui *pGuiObject)
{
    pGuiObject->setId(_IdIndividual);
    _IdIndividual++;
    previousCoordX = pIndexi * PIXELS_POS;
    previousCoordY = pIndexj * PIXELS_POS;
    actualCoordX = (pIndexi+1) * PIXELS_POS;
    _objectGui = pGuiObject;
    MyThread* _walkThread = new MyThread((void*)updateRightPos,nullptr);
    _walkThread->run();
}

void Scene::upWalk(int pIndexi, int pIndexj, ObjectsGui *pGuiObject)
{
    pGuiObject->setId(_IdIndividual);
    _IdIndividual++;
    previousCoordX = pIndexi * PIXELS_POS;
    previousCoordY = pIndexj * PIXELS_POS;
    actualCoordY = (pIndexj-1) * PIXELS_POS;
    _objectGui = pGuiObject;
    MyThread* _walkThread = new MyThread((void*)updateUpPos,nullptr);
    _walkThread->run();

}

void Scene::downWalk(int pIndexi, int pIndexj, ObjectsGui *pGuiObject)
{
    pGuiObject->setId(_IdIndividual);
    _IdIndividual++;
    previousCoordX = pIndexi * PIXELS_POS;
    previousCoordY = pIndexj * PIXELS_POS;
    actualCoordY = (pIndexj+1) * PIXELS_POS;
    _objectGui = pGuiObject;
    MyThread* _walkThread = new MyThread((void*)updateDownPos,nullptr);
    _walkThread->run();

}

void* Scene::updateLeftPos()
{
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;
    while (previousCoordX != actualCoordX)
    {
        pthread_mutex_lock(&mutex);
        previousCoordX -= 10;
        _objectGui->setPos(previousCoordX, previousCoordY);
        scene->addItem(_objectGui);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

}

void *Scene::updateRightPos()
{
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;
    while (previousCoordX != actualCoordX)
    {
        pthread_mutex_lock(&mutex);
        previousCoordX += 10;
        _objectGui->setPos(previousCoordX, previousCoordY);
        scene->addItem(_objectGui);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

}

void* Scene::updateUpPos()
{
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;
    while (previousCoordY != actualCoordY)
    {
        pthread_mutex_lock(&mutex);
        previousCoordY -= 10;
        _objectGui->setPos(previousCoordX, previousCoordY);
        scene->addItem(_objectGui);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* Scene::updateDownPos()
{
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;
    while (previousCoordY != actualCoordY)
    {
        pthread_mutex_lock(&mutex);
        previousCoordY += 10;
        _objectGui->setPos(previousCoordX, previousCoordY);
        scene->addItem(_objectGui);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

}



void *Scene::paintMap()
{
    cout << "painting maaaap" << endl;
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;

    for(int i=0; i < _guiMapActual->getHeight(); i++)
    {
        for(int j=0; j< _guiMapActual->getWidth();j++)
        {

            pthread_mutex_lock(&mutex);
            cout << "entro a recorrer el mapa para pintar " << endl;
            ObjectsGui* _guiObject = new ObjectsGui((*_guiMapActual)[i][j]);
    //Si la matriz anterior esta llena de ceros
            bool _previo = verificaMapPrevious();
            if (_previo)
            {
                if(_guiMapActual[i][j] != 0)
                {
                    _guiObject->setId(_IdIndividual);
                    _IdIndividual++;
                }

                _guiObject->setPos(((i*PIXELS_POS)), ((j*PIXELS_POS)));
                scene->addItem(_guiObject);
            }

     //Si el elemento de la matriz anterior es diferente que el elemento de la actual
            else if (_guiMapPrevious[i][j] != _guiMapActual[i][j])
            {
                //esquina superior izquierda
                if (i == MIN_INDEX && j == MIN_INDEX)
                {
                    if (_guiMapActual[i+1][j] == _guiMapPrevious[i][j])
                        rightWalk(i,j,_guiObject);
                    else if (_guiMapActual[i][j+1] == _guiMapPrevious[i][j])
                        downWalk(i,j,_guiObject);
                }
                //Esquina superior derecha
                else if (i == MIN_INDEX && j == MAX_INDEX)
                {
                    if (_guiMapActual[i-1][j] == _guiMapPrevious[i][j])
                        leftWalk(i,j,_guiObject);
                    else if (_guiMapActual[i][j+1] == _guiMapPrevious[i][j])
                        downWalk(i,j,_guiObject);
                }
                //esquina inferior izquierda
                else if (i == MAX_INDEX && j == MIN_INDEX)
                {
                    if (_guiMapActual[i+1][j] == _guiMapPrevious[i][j])
                        rightWalk(i,j,_guiObject);
                    else if (_guiMapActual[i][j-1] == _guiMapPrevious[i][j])
                        upWalk(i,j,_guiObject);
                }
                //esquina inferior derecha
                else if (i == MAX_INDEX && j == MAX_INDEX)
                {
                    if (_guiMapActual[i-1][j] == _guiMapPrevious[i][j])
                        leftWalk(i,j,_guiObject);
                    else if (_guiMapActual[i][j-1] == _guiMapPrevious[i][j])
                        upWalk(i,j,_guiObject);
                }
                //cualquier otra posicion
                else
                {
                    if (_guiMapActual[i-1][j] == _guiMapPrevious[i][j])
                        leftWalk(i,j,_guiObject);
                    else if (_guiMapActual[i+1][j] == _guiMapPrevious[i][j])
                        rightWalk(i,j,_guiObject);
                    else if (_guiMapActual[i][j+1] == _guiMapPrevious[i][j])
                        downWalk(i,j,_guiObject);
                    else
                        upWalk(i,j,_guiObject);
                }
                _IdIndividual++;
            }
      //Si los elementos son iguales, nada mas pinta el objeto
            else
            {
                cout << "PaintMap" << endl;
                    if(_guiMapActual[i][j] != 0)
                    {
                        _guiObject->setId(_IdIndividual);
                        _IdIndividual++;
                    }
                    _guiObject->setPos(((i*PIXELS_POS)), ((j*PIXELS_POS)));
                    scene->addItem(_guiObject);

            }
            pthread_mutex_unlock(&mutex);
            sleep(2);
        }
    }
    _guiMapPrevious = _guiMapActual;
    _guiMapActual->llenarMatriz(0);
}


