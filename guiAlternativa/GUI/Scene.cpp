#include "Scene.h"

QGraphicsScene* Scene:: scene;
Vector<int>* Scene::_guiMap;
Vector<ObjectsGui*>* Scene::_matrizBorradoMap;
int Scene::_IdIndividual  = 0;


Scene::Scene() : QGraphicsView()
{
   /* playScene = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    for(int i = 0; i < 5; i++)
    {
        playlist->addMedia(QUrl::fromLocalFile("/home/david/Desktop/guiAlternativa/GUI/medieval2.mp3"));
        playlist->addMedia(QUrl::fromLocalFile("/home/david/Desktop/guiAlternativa/GUI/medieval.mp3"));

    }
    playlist->setCurrentIndex(1);

    playScene->setPlaylist(playlist);
    playScene->setVolume(15);
    playScene->play();*/

    _guiMap = new Vector<int>(WIDTH_MAP,HEIGHT_MAP);
    _guiMap->llenarMatriz(0);
    _matrizBorradoMap = new Vector<ObjectsGui*>(WIDTH_MAP,HEIGHT_MAP);


    scene = new QGraphicsScene(0,0,WIDTH_POS,HEIGHT_POS);
    QPixmap _background("/home/david/Desktop/guiAlternativa/GUI/imagenes GUI/grass.png");
    setScene(scene);
    scene->setBackgroundBrush(_background);
                              //.scaled(WIDTH_SCENE,HEIGHT_SCENE,Qt::IgnoreAspectRatio,
                                //                 Qt::SmoothTransformation));

    //MyThread* _threadGui = new MyThread((void*)paintMap,nullptr);
    cout << "antes del run" << endl;
    //_threadGui->run();


}

Vector<int>* Scene::getMap()
{
    return _guiMap;
}


void Scene::setMap(Vector<int> *pMatrix)
{
    cout << "paso matriz" << endl;

    _guiMap = pMatrix;


    /*MyThread* paintThread = new MyThread((void*)paintMap,nullptr);
    paintThread->run();*/
    paintMap();
    cout << "paso paintmap" << endl;
}





void *Scene::paintMap()
{
    cout << "painting maaaap" << endl;
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;

    for(int i=0; i < _guiMap->getWidth(); i++)
    {
        for(int j=0; j< _guiMap->getHeight();j++)
        {
            pthread_mutex_lock(&mutex);            

            if((*_guiMap)[i][j] != 0 && (*_guiMap)[i][j]!=-1 )
            {

                ObjectsGui* _guiObject = new  ObjectsGui(((*_guiMap)[i][j]));
                _guiObject->setId(_IdIndividual);
                _IdIndividual++;
                _guiObject->setPos(((i*PIXELS_POS)), ((j*PIXELS_POS)));
                scene->addItem(_guiObject);
                cout <<"esta pintando" << endl;
                (*_matrizBorradoMap)[i][j] = _guiObject;
            }
            //(*_guiMap)[1][1]=-1;
            //(*_guiMap)[4][4]=-1;

            if((*_guiMap)[i][j] == -1){
                scene->removeItem(*(_matrizBorradoMap[i][j]));
            }
            pthread_mutex_unlock(&mutex);

        }        
    }

}



