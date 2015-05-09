#include "obstacle.h"
#include "Scene.h"

Obstacle::Obstacle(int pKindObstacle)
{
    int randomPosX = rand()%WIDTH_POS;
    int randomPosY = rand()%HEIGHT_POS;

    QPixmap _river("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/lake.png");
    QPixmap _rocks("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/roca.gif");
    QPixmap _trees("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/tree.gif");
    std::cout << pKindObstacle << std::endl;
    setPos(randomPosX, randomPosY);

    switch(pKindObstacle)
    {
    case 0:
        setPixmap(_rocks);
        _type = "rio";
        break;
    case 1:
        setPixmap(_river);
        _type = "roca";
        break;
    default:
        setPixmap(_trees);
        _type = "arbol";
        break;

    }

}

std::string Obstacle::getType()
{
    return _type;
}
