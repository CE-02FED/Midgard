#ifndef OBJECTSGUI_H
#define OBJECTSGUI_H
#include <QGraphicsPixmapItem>
#include <Constants.h>
#include <QGraphicsSceneMouseEvent>
#include <informationindividual.h>
#include "GuiFacade.h"
#include "godsinformation.h"
#include "puebloinformation.h"

#define MAX_PUEBLO 59
#define MIN_PUEBLO 56
#define MID_PUEBLO 57
#define MAX_GODS 55
#define MIN_GODS 52
#define MAX_GIANTS 51
#define MIN_GIANTS 40
#define MAX_ELVES 39
#define MIN_ELVES 28
#define MAX_DWARVES 27
#define MIN_DWARVES 16
#define MAX_DARKELVES 15
#define MIN_DARKELVES 4
#define DARK_ELVES_IMG 60
#define DWARVES_IMG 61
#define ELVES_IMG 62
#define GIANTS_IMG 63

class GuiFacade;
class ObjectsGui : public QGraphicsPixmapItem{
public:
    ObjectsGui(int pIdKind);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    unsigned int _ID;
    void setId(int pId);
    GuiFacade* _guiFacade;
    informationIndividual* indInfo;
    godsInformation* _godsInfo;
    puebloInformation* _puebloInfo;
private:
    int _imageId;
};

#endif
