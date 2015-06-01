#include "informationindividual.h"
#include "ui_informationindividual.h"

informationIndividual::informationIndividual(int pIdFather, int pIdMother, int pIndvFitness, int pIdImage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::informationIndividual)
{
    ui->setupUi(this);

    string _fatherId, _motherId, _fitness;
    _fatherId = to_string(pIdFather);
    _motherId = to_string(pIdMother);
    _fitness = to_string(pIndvFitness);
    string imageInd = Constants::IMAGEN + to_string(pIdImage) + Constants::IMAGEN_FORMATO_GIF;
    QString _image = imageInd.c_str();
    QMovie* _movie = new QMovie(_image);
    QString idpadre = _fatherId.c_str();
    QString idmadre = _motherId.c_str();
    QString fitnessindv = _fitness.c_str();

    ui->imageInd->setMovie(_movie);
    ui->IdFather->setText(idpadre);
    ui->IdMother->setText(idmadre);
    ui->Fitness->setText(fitnessindv);
    _movie->start();


}

informationIndividual::~informationIndividual()
{
    delete ui;
}
