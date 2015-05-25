#ifndef OBJECTSGUI_H
#define OBJECTSGUI_H
#include <QGraphicsPixmapItem>
#include <typeinfo>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <Constants.h>
#include <QGraphicsSceneMouseEvent>
#include <informationindividual.h>
#include "GuiFacade.h"

class GuiFacade;
class ObjectsGui : public QGraphicsPixmapItem{
public:

    ObjectsGui(int pIdKind);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    unsigned int _ID;
    void setId(int pId);
    GuiFacade* _guiFacade;
    informationIndividual* indInfo;
};

#endif
