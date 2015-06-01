#ifndef INFORMATIONINDIVIDUAL_H
#define INFORMATIONINDIVIDUAL_H

#include <QMainWindow>
#include <string>
#include <QString>
#include "Constants.h"
#include <QMovie>

using namespace std;

namespace Ui {
class informationIndividual;
}

class informationIndividual : public QMainWindow
{
    Q_OBJECT

public:
    explicit informationIndividual(int pIdFather,int pIdMother,int pIndvFitness, int pIdImage, QWidget *parent = 0);
    ~informationIndividual();

private:
    Ui::informationIndividual *ui;
};

#endif // INFORMATIONINDIVIDUAL_H
