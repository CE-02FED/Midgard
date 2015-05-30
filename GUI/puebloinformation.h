#ifndef PUEBLOINFORMATION_H
#define PUEBLOINFORMATION_H

#include <QMainWindow>
#include <iostream>
#include "Constants.h"

namespace Ui {
class puebloInformation;
}

class puebloInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit puebloInformation(string pNamePueblo, int pIdImage, int pAmountPeople,
                               int pFittest, int pWorstFitness, QWidget *parent = 0);
    ~puebloInformation();

private:
    Ui::puebloInformation *ui;
};

#endif // PUEBLOINFORMATION_H
