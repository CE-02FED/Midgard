#ifndef INDIVIDUALGUI_H
#define INDIVIDUALGUI_H
#include <QGraphicsPixmapItem>
#include <typeinfo>
#include <QKeyEvent>
#include <QList>
#include <QPointF>

class IndividualGui : public QGraphicsPixmapItem{
public:

    IndividualGui(int pIdName);

    void keyPressEvent(QKeyEvent* event);
    std::string getType();
    void setId(int pId);
    int getId();
private:
    QPointF prevPos;
    std::string _type;
    unsigned int _Id;
};

#endif
