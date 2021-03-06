#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QUrl>
#include <QFileInfo>
#include "objectsGui.h"
#include "string.h"
#include "time.h"
#include "unistd.h"
//#include <QtMultimedia>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "vector.h"

#define WIDTH_SCENE 800
#define HEIGHT_SCENE 800
#define WIDTH_POS 1875
#define HEIGHT_POS 1875
#define PIXELS_POS 75
#define WIDTH_MAP 25
#define HEIGHT_MAP 25

using namespace std;

class ObjectsGui;
class Scene: public QGraphicsView{
public:

    Scene();
    static QGraphicsScene* scene;
    void* paintMap();
    Vector<int> *getMap();
    void setMap(Vector<int>* pMatrix);

private:
    QMediaPlayer* playScene;
    QMediaPlaylist* playlist;
    static Vector<int>* _guiMap;
    void clearScreen();
    static Vector<ObjectsGui*>* _objectMap;
    static int _IdIndividual;



};

#endif // SCENE_H
