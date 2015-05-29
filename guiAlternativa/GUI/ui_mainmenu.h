/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *Quit;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 400);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Serif"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 160, 111, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        Quit = new QPushButton(centralWidget);
        Quit->setObjectName(QStringLiteral("Quit"));
        Quit->setGeometry(QRect(140, 230, 111, 41));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        Quit->setFont(font2);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 341, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("URW Chancery L"));
        font3.setPointSize(26);
        font3.setItalic(true);
        label->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Midgard", 0));
        pushButton->setText(QApplication::translate("MainWindow", "START", 0));
        Quit->setText(QApplication::translate("MainWindow", "QUIT", 0));
        label->setText(QApplication::translate("MainWindow", "MIDGARD", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
