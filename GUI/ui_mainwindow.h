/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/


#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QHBoxLayout"
#include "iostream"
using namespace std;


QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *start;
    QPushButton *quit;
    QLabel *label;
    QLabel *label2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 375);
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Serif"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 500, 375));
        QPixmap menuBackground("/home/javier/WorkspaceQT/GUI/imagenes GUI/menu.jpg");
        label->setPixmap(menuBackground);

        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("pushButton"));
        start->setGeometry(QRect(140, 160, 111, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        start->setFont(font1);

        quit = new QPushButton(centralWidget);
        quit->setObjectName(QStringLiteral("Quit"));
        quit->setGeometry(QRect(140, 230, 111, 41));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        quit->setFont(font2);

        QFont font3;
        font3.setFamily(QStringLiteral("URW Chancery L"));
        font3.setPointSize(30);
        font3.setItalic(true);

        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label"));
        label2->setGeometry(QRect(130, 10, 185, 50));
        label2->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
      //  connect(start, SIGNAL(clicked()), this, SLOT(print()));


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Midgard", 0));
        start->setText(QApplication::translate("MainWindow", "START", 0));
        quit->setText(QApplication::translate("MainWindow", "QUIT", 0));
        label2->setText(QApplication::translate("MainWindow", "MIDGARD", 0));
    }


};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

