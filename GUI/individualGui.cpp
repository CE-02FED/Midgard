#include "individualGui.h"
#include "Scene.h"


IndividualGui::IndividualGui(int pIdName){

    //QGraphicsItem* parent = NULL;
    int randomPosX = rand()%WIDTH_POS;
    int randomPosY = rand()%HEIGHT_POS;
    QPixmap _guerrero("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/guerrero.png");
    QPixmap _arquero("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/arquero.png");
    QPixmap _alquimista("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/alquimista.png");
    QPixmap _mujer("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/mujer.png");
    QPixmap _mago("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/mago.png");
    QPixmap _elfo("/home/david/Documents/cLion-Projects/Midgard/GUI/imagenes GUI/elfo.png");
    setPos(randomPosX, randomPosY);

    switch (pIdName)
    {
    case 0:
       setPixmap(_guerrero);
       _type = "guerrero";
        break;
    case 1:
        setPixmap(_arquero);
        _type = "arquero";
        break;
    case 2:
        setPixmap(_alquimista);
        _type = "alquimista";
        break;
    case 3:
        setPixmap(_mujer);
        _type = "mujer";
        break;
    case 4:
        setPixmap(_mago);
        _type = "mago";
        break;
    default:
        setPixmap(_elfo);
        _type = "elfo";
        break;

    }


}

std::string IndividualGui::getType()
{
    return _type;
}

void IndividualGui::setId(int pId)
{
    _Id = pId;
}

int IndividualGui::getId()
{
    return _Id;
}


void IndividualGui::keyPressEvent(QKeyEvent *event)
{

    if (event->MouseMove)
    {
        prevPos = pos();
        int xPos = x();
        int yPos = y() - boundingRect().height();
        setPos(xPos,yPos);
    }

    else if (event->key() == Qt::Key_Down)
    {
        prevPos = pos();
        int xPos = x();
        int yPos = y() + boundingRect().height();
        setPos(xPos,yPos);
    }

    else if (event->key() == Qt::Key_Right)
    {
        prevPos = pos();
        int xPos = x() + boundingRect().width();
        int yPos = y();
        setPos(xPos,yPos);
    }

    else if (event->key() == Qt::Key_Left)
    {
        prevPos = pos();
        int xPos = x() - boundingRect().width();
        int yPos = y();
        setPos(xPos,yPos);
    }

}



