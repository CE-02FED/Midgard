#include "objectsGui.h"

ObjectsGui::ObjectsGui(int pIdKind)
{
    string _Imagen = Constants::IMAGEN + to_string(pIdKind) + Constants::IMAGEN_FORMATO;
    QPixmap _image(_Imagen.c_str());
    this->setPixmap(_image);
}


void ObjectsGui::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    cout << "click" << endl;

    _guiFacade = GuiFacade::getInstance();
    _guiFacade->getGenealogia(1,_ID);
    cout << _guiFacade->getTmpIdFather() << endl;
    cout << _guiFacade->getTmpIdMother() << endl;
    cout << _guiFacade->getTmpFitness() << endl;
    indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                        _guiFacade->getTmpFitness());
    indInfo->show();


}

void ObjectsGui::setId(int pId)
{
    _ID = pId;
}
