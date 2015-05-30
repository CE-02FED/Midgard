#include "Scene.h"

QGraphicsScene* Scene:: scene;
Vector<int>* Scene::_guiMap;
Vector<ObjectsGui*>* Scene::_objectMap;
int Scene::_IdIndividual  = 0;


Scene::Scene() : QGraphicsView()
{
   playScene = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    for(int i = 0; i < 5; i++)
    {
        playlist->addMedia(QUrl::fromLocalFile("/home/javier/WorkspaceQT/GUI/medieval2.mp3"));
        playlist->addMedia(QUrl::fromLocalFile("/home/javier/WorkspaceQT/GUI/medieval2.mp3"));

    }
    playlist->setCurrentIndex(1);

    playScene->setPlaylist(playlist);
    playScene->setVolume(15);
    playScene->play();

    _guiMap = new Vector<int>(WIDTH_MAP,HEIGHT_MAP);
    _guiMap->llenarMatriz(0);
    _objectMap = new Vector<ObjectsGui*>(WIDTH_MAP,HEIGHT_MAP);


    scene = new QGraphicsScene(0,0,WIDTH_POS,HEIGHT_POS);
    QPixmap _background("/home/javier/WorkspaceQT/GUI/imagenes GUI/grass.png");


    setScene(scene);
    scene->setBackgroundBrush(_background);        

    ObjectsGui* _guiObject1 = new  ObjectsGui(56);
    _guiObject1->setPos(((0*PIXELS_POS)), ((0*PIXELS_POS)));
    ObjectsGui* _guiObject2 = new  ObjectsGui(58);
    _guiObject2->setPos(((0*PIXELS_POS)), ((24*PIXELS_POS)));
    ObjectsGui* _guiObject3 = new  ObjectsGui(57);
    _guiObject3->setPos(((24*PIXELS_POS)), ((0*PIXELS_POS)));
    ObjectsGui* _guiObject4 = new  ObjectsGui(59);
    _guiObject4->setPos(((24*PIXELS_POS)), ((24*PIXELS_POS)));

    scene->addItem(_guiObject1);
    scene->addItem(_guiObject2);
    scene->addItem(_guiObject3);
    scene->addItem(_guiObject4);




}

Vector<int>* Scene::getMap()
{
    return _guiMap;
}


void Scene::setMap(Vector<int> *pMatrix)
{
    clearScreen();

    _guiMap = pMatrix;

    paintMap();

}

void Scene::clearScreen(){
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;

    for(int i=0; i < _guiMap->getWidth(); i++)
    {
        for(int j=0; j< _guiMap->getHeight();j++)
        {
            pthread_mutex_lock(&mutex);

            if((*_guiMap)[i][j] != 0 )
            {
                if(((i == 0  && j == 0) || (i==0 && j==24) || (i==24&& j==0) || (i==24 && j==24) ));

                else
                {
                    if((*_objectMap)[i][j]){
                    scene->removeItem((*_objectMap)[i][j]);
                    }
                    else{
                        cout<<"null"<<endl;
                    }

                }
            }

            pthread_mutex_unlock(&mutex);

        }
    }
}





void *Scene::paintMap()
{
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;

    for(int i=0; i < _guiMap->getWidth(); i++)
    {
        for(int j=0; j< _guiMap->getHeight();j++)
        {
            pthread_mutex_lock(&mutex);

            if((*_guiMap)[i][j] != 0 )
            {
                if(((i == 0  && j == 0) || (i==0 && j==24) || (i==24&& j==0) || (i==24 && j==24) ));

                else
                {
                    ObjectsGui* _guiObject = new  ObjectsGui(((*_guiMap)[i][j]));
                    if(_guiObject){
                        _guiObject->setId(_IdIndividual);
                        _IdIndividual++;
                        _guiObject->setPos(((i*PIXELS_POS)), ((j*PIXELS_POS)));
                        scene->addItem(_guiObject);
                        (*_objectMap)[i][j] = _guiObject;
                    }
                    else{
                        cout<<"null"<<endl;
                    }


                }
            }

            pthread_mutex_unlock(&mutex);

        }
    }

}



