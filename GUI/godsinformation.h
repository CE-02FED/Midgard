#ifndef GODSINFORMATION_H
#define GODSINFORMATION_H

#include <QMainWindow>

namespace Ui {
class godsInformation;
}

class godsInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit godsInformation(QWidget *parent = 0);
    ~godsInformation();

private:
    Ui::godsInformation *ui;
};

#endif // GODSINFORMATION_H
