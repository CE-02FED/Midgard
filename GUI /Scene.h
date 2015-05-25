#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "objectsGui.h"
#include "string.h"
#include "time.h"
#include "unistd.h"
#include <QtMultimedia>
#include <QMediaPlaylist>
//#include "mythread.h"


#include "vector.h"

#define WIDTH_SCENE 800
#define HEIGHT_SCENE 800
#define WIDTH_POS 5000
#define HEIGHT_POS 5000
#define PIXELS_POS 100
#define WIDTH_MAP 50
#define HEIGHT_MAP 50
#define MAX_INDEX 50
#define MIN_INDEX 0
#define MAP_POSITIONS 2500

using namespace std;

class ObjectsGui;
class Scene: public QGraphicsView{
public:

    Scene();
    static void* start();
    static QGraphicsScene* scene;
    static void* paintMap();
    Vector<int> *getMapActual();
    void setMapActual(Vector<int>* pMatrixActual);
    Vector<int> *getMapPrevious();

private:
    QMediaPlayer* playScene;
    QMediaPlaylist* playlist;
    static Vector<int>* _guiMapActual;
    static Vector<int>* _guiMapPrevious;
    static int _IdIndividual;
    static ObjectsGui* _objectGui;
    static int previousCoordX, previousCoordY, actualCoordX, actualCoordY;

    static bool verificaMapPrevious();
    static void leftWalk (int pIndexi, int pIndexj, ObjectsGui* pGuiObject);
    static void rightWalk(int pIndexi, int pIndexj, ObjectsGui* pGuiObject);
    static void upWalk   (int pIndexi, int pIndexj, ObjectsGui* pGuiObject);
    static void downWalk (int pIndexi, int pIndexj, ObjectsGui* pGuiObject);
    static void* updateLeftPos();
    static void* updateRightPos();
    static void* updateUpPos();
    static void* updateDownPos();


};

#endif // SCENE_H
