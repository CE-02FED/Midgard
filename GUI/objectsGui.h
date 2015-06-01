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
///////////////////////////////////////
#define MIN_FIGHTER 4
#define MAX_FIGHTER 46
#define MIN_MONK 5
#define MAX_MONK 47
#define MIN_RED_MAGE 6
#define MAX_RED_MAGE 48
#define MIN_BLACK_MAGE 7
#define MAX_BLACK_MAGE 49
#define MIN_WHITE_MAGE 8
#define MAX_WHITE_MAGE 50
#define MIN_THIEF 9
#define MAX_THIEF 51
///////////////////////////////////////
#define FIGHTER_IMG 60
#define MONK_IMG 61
#define RED_MAGE_IMG 62
#define BLACK_MAGE_IMG 63
#define WHITE_MAGE_IMG 64
#define THIEF_IMG 65

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
