#include "puebloinformation.h"
#include "ui_puebloinformation.h"

puebloInformation::puebloInformation(string pNamePueblo, int pIdImage, int pAmountPeople,
                                     int pFittest, int pWorstFitness, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::puebloInformation)
{
    ui->setupUi(this);

    string strFittest, strAmount, strWorstFitness;
    strFittest = to_string(pFittest);
    strAmount = to_string(pAmountPeople);
    strWorstFitness = to_string(pWorstFitness);

    string img = Constants::IMAGEN + to_string(pIdImage) + Constants::IMAGEN_FORMATO;
    QPixmap _imageTown(img.c_str());
    ui->labelImage->setPixmap(_imageTown);
    QString _amountPeople = strAmount.c_str();
    QString _fittest = strFittest.c_str();
    QString _namePueblo = pNamePueblo.c_str();
    QString _worstFitness = strWorstFitness.c_str();

    ui->nameTown->setText(_namePueblo);
    ui->amountLabel->setText(_amountPeople);
    ui->labelFittest->setText(_fittest);
    ui->labelWorstFitness->setText(_worstFitness);

}

puebloInformation::~puebloInformation()
{
    delete ui;
}
