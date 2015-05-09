#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <typeinfo>

class Obstacle : public QGraphicsPixmapItem{
public:

    Obstacle(int pKindObstacle);
    std::string getType();

private:

    std::string _type;
};

#endif

