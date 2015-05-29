#include "godsinformation.h"
#include "ui_godsinformation.h"

godsInformation::godsInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::godsInformation)
{
    ui->setupUi(this);
}

godsInformation::~godsInformation()
{
    delete ui;
}
