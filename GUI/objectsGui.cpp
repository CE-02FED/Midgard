#include "objectsGui.h"

ObjectsGui::ObjectsGui(int pIdKind)
{
    _imageId = pIdKind;

    string _Imagen = Constants::IMAGEN + to_string(pIdKind) + Constants::IMAGEN_FORMATO;
    QPixmap _image(_Imagen.c_str());
    this->setPixmap(_image);
}


void ObjectsGui::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    cout << "imagen ID: " << _imageId << endl;
    _guiFacade = GuiFacade::getInstance();

    if (MIN_DARKELVES <= _imageId && _imageId <= MAX_GIANTS)
    {
        _guiFacade->getGenealogia(1,_ID);


        if (_imageId == 4 || _imageId == 10 || _imageId == 16 || _imageId == 22 || _imageId == 28 ||
               _imageId == 34 || _imageId == 40 || _imageId == 46)
        {
            indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                                        _guiFacade->getTmpFitness(), FIGHTER_IMG);
        }
        else if (_imageId == 5 || _imageId == 11 || _imageId == 17 || _imageId == 23 || _imageId == 29 ||
               _imageId == 35 || _imageId == 41 || _imageId == 47)
        {
            indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                                        _guiFacade->getTmpFitness(), MONK_IMG);
        }
        else if (_imageId == 6 || _imageId == 12 || _imageId == 18 || _imageId == 24 || _imageId == 30 ||
               _imageId == 36 || _imageId == 42 || _imageId == 48)
        {
            indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                                        _guiFacade->getTmpFitness(), RED_MAGE_IMG);
        }
        else if (_imageId == 7 || _imageId == 13 || _imageId == 19 || _imageId == 25 || _imageId == 31 ||
               _imageId == 37 || _imageId == 43 || _imageId == 49)
        {
            indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                                        _guiFacade->getTmpFitness(), BLACK_MAGE_IMG);
        }
        else if (_imageId == 8 || _imageId == 14 || _imageId == 20 || _imageId == 26 || _imageId == 32 ||
               _imageId == 38 || _imageId == 44 || _imageId == 50)
        {
            indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                                        _guiFacade->getTmpFitness(), WHITE_MAGE_IMG);
        }
        else
        {
            indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                                        _guiFacade->getTmpFitness(), THIEF_IMG);
        }

        indInfo->show();

    }

    else if (MIN_GODS <= _imageId && _imageId <= MAX_GODS)
    {
        _godsInfo = new godsInformation();
        _godsInfo->show();
    }

    else if (MIN_PUEBLO <= _imageId && _imageId <= MAX_PUEBLO)
    {
        if(_imageId == MIN_PUEBLO)
        {
            _guiFacade->getPuebloInfo(1);
            _puebloInfo = new puebloInformation("DARK ELVES",_imageId,_guiFacade->getAmountPeople(),
                                             _guiFacade->getFittest(), _guiFacade->getWorstFitness());
        }
        else if(_imageId == MAX_PUEBLO)
        {
            _guiFacade->getPuebloInfo(4);
            _puebloInfo = new puebloInformation("GIANTS",_imageId,_guiFacade->getAmountPeople(),
                                                 _guiFacade->getFittest(), _guiFacade->getWorstFitness());

        }
        else if(_imageId == MID_PUEBLO)
        {
            _guiFacade->getPuebloInfo(2);
            _puebloInfo = new puebloInformation("DWARVES",_imageId,_guiFacade->getAmountPeople(),
                                                 _guiFacade->getFittest(), _guiFacade->getWorstFitness());

        }
        else
        {
            _guiFacade->getPuebloInfo(3);
            _puebloInfo = new puebloInformation("ELVES",_imageId,_guiFacade->getAmountPeople(),
                                                _guiFacade->getFittest(), _guiFacade->getWorstFitness());

        }

        _puebloInfo->show();
    }
}

void ObjectsGui::setId(int pId)
{
    _ID = pId;
}
