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
    cout << "clickkkkk" <<  endl;
    _guiFacade = GuiFacade::getInstance();
    //_guiFacade->getMap();
    if (MIN_DARKELVES <= _imageId && _imageId <= MAX_GIANTS)
    {
        _guiFacade->getGenealogia(1,_ID);
        indInfo = new informationIndividual(_guiFacade->getTmpIdFather(), _guiFacade->getTmpIdMother(),
                                            _guiFacade->getTmpFitness());
        indInfo->show();
    }

    else if (MIN_GODS <= _imageId && _imageId <= MAX_GODS)
    {
        _godsInfo = new godsInformation();
        _godsInfo->show();
    }
    else if (MIN_PUEBLO <= _imageId && _imageId <= MAX_PUEBLO)
    {
        //DARK ELVES
        if(_imageId == MIN_PUEBLO)
        {
            _guiFacade->getPuebloInfo(1);
            _puebloInfo = new puebloInformation("DARK ELVES",_imageId,_guiFacade->getAmountPeople(),
                                                _guiFacade->getFittest(), _guiFacade->getWorstFitness());

            //_puebloInfo = new puebloInformation("DARK ELVES",DARK_ELVES_IMG, 45, 3500, 123);
            _puebloInfo->show();
        }
        //GIANTS
        else if(_imageId == MAX_PUEBLO)
        {
            _guiFacade->getPuebloInfo(4);
            _puebloInfo = new puebloInformation("GIANTS",_imageId,_guiFacade->getAmountPeople(),
                                                 _guiFacade->getFittest(), _guiFacade->getWorstFitness());

             //_puebloInfo = new puebloInformation("GIANTS",GIANTS_IMG, 87, 3365, 765);
             _puebloInfo->show();

        }
        //DWARVES
        else if(_imageId == MID_PUEBLO)
        {
            _guiFacade->getPuebloInfo(2);
            _puebloInfo = new puebloInformation("DWARVES",_imageId,_guiFacade->getAmountPeople(),
                                                 _guiFacade->getFittest(), _guiFacade->getWorstFitness());

             //_puebloInfo = new puebloInformation("DWARVES",DWARVES_IMG, 34, 2770, 544);
             _puebloInfo->show();

        }
        //ELVES
        else
        {
            _guiFacade->getPuebloInfo(3);
            _puebloInfo = new puebloInformation("ELVES",_imageId,_guiFacade->getAmountPeople(),
                                                _guiFacade->getFittest(), _guiFacade->getWorstFitness());

             //_puebloInfo = new puebloInformation("ELVES",ELVES_IMG, 12, 2450, 56);
             _puebloInfo->show();

        }
    }

}

void ObjectsGui::setId(int pId)
{
    _ID = pId;
}
