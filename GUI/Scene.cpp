#include "Scene.h"
 QGraphicsScene* Scene:: scene;

Scene::Scene(): QGraphicsView(){


    scene = new QGraphicsScene(0,0,WIDTH_SCENE,HEIGHT_SCENE);
    QPixmap _background("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/grasscuad.png");
    setScene(scene);
    scene->setBackgroundBrush(_background.scaled(WIDTH_SCENE,HEIGHT_SCENE,Qt::IgnoreAspectRatio,
                                        Qt::SmoothTransformation));

    int obstacles = 25;

    for (int i=0; i < obstacles; i++)
    {

        int randomObstacle = rand()%OBSTACLE_TYPES;
        Obstacle* obstacle = new Obstacle(randomObstacle);
        scene->addItem(obstacle);

    }
}


void* Scene::start()
{

    IndividualGui* _population[AMOUNT_POPULATION];
    for(int i=0; i<AMOUNT_POPULATION; i++)
    {
         int randomPerson = rand()%PEOPLE_TYPES;
         IndividualGui* individuo = new IndividualGui(randomPerson);
         individuo->setId(i);
         _population[i] = individuo;
         scene->addItem(individuo);
         //std::cout << "Tipo: " << individuo->getType() << std::endl;
         usleep(1000000);
     }

}

/*void Scene::receiveMesssage(string pMessage)
{

}*/


/*IndividualGui *Scene::findIndividualById(int pId)
{
    return _population[pId];
}

void Scene::deleteIndividualById(int pId)
{
    delete _population[pId];
}
*/
