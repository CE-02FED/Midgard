#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "individualGui.h"
#include "obstacle.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "unistd.h"
#include "mythread.h"

#define AMOUNT_POPULATION 75
#define WIDTH_SCENE 600
#define HEIGHT_SCENE 600
#define WIDTH_POS 1000
#define HEIGHT_POS 800
#define PEOPLE_TYPES 6
#define OBSTACLE_TYPES 3

using namespace std;
class Scene: public QGraphicsView{
public:

    Scene();

    static void* start();

    IndividualGui* findIndividualById(int pId);

    void deleteIndividualById(int pId);

    static QGraphicsScene* scene;

    //void Scene::receiveMesssage(string pMessage);


};

#endif // SCENE_H
