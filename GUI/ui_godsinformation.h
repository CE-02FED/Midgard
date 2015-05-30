/********************************************************************************
** Form generated from reading UI file 'godsinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GODSINFORMATION_H
#define UI_GODSINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_godsInformation
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menubar;
    QMenu *menuGods_Info;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *godsInformation)
    {
        if (godsInformation->objectName().isEmpty())
            godsInformation->setObjectName(QStringLiteral("godsInformation"));
        godsInformation->resize(459, 421);
        centralwidget = new QWidget(godsInformation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 221, 41));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setPointSize(14);
        font.setItalic(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 110, 81, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8("imagenes GUI/imagen52.png")));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 110, 81, 81));
        label_3->setPixmap(QPixmap(QString::fromUtf8("imagenes GUI/imagen53.png")));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 110, 71, 81));
        label_4->setPixmap(QPixmap(QString::fromUtf8("imagenes GUI/imagen54.png")));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(360, 100, 71, 91));
        label_5->setPixmap(QPixmap(QString::fromUtf8("imagenes GUI/imagen55.png")));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 260, 421, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("URW Gothic L"));
        font1.setPointSize(10);
        font1.setItalic(true);
        label_6->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 80, 111, 17));
        QFont font2;
        font2.setFamily(QStringLiteral("URW Chancery L"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_7->setFont(font2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 230, 131, 17));
        QFont font3;
        font3.setFamily(QStringLiteral("URW Chancery L"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        label_8->setFont(font3);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 310, 421, 21));
        label_9->setFont(font1);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 350, 361, 21));
        label_10->setFont(font1);
        godsInformation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(godsInformation);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 459, 25));
        menuGods_Info = new QMenu(menubar);
        menuGods_Info->setObjectName(QStringLiteral("menuGods_Info"));
        godsInformation->setMenuBar(menubar);
        statusbar = new QStatusBar(godsInformation);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        godsInformation->setStatusBar(statusbar);

        menubar->addAction(menuGods_Info->menuAction());

        retranslateUi(godsInformation);

        QMetaObject::connectSlotsByName(godsInformation);
    } // setupUi

    void retranslateUi(QMainWindow *godsInformation)
    {
        godsInformation->setWindowTitle(QApplication::translate("godsInformation", "MainWindow", 0));
        label->setText(QApplication::translate("godsInformation", "GODS INFORMATION", 0));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QApplication::translate("godsInformation", "Deities are characterized by their great power and their ability ", 0));
        label_7->setText(QApplication::translate("godsInformation", "CHARACTERS", 0));
        label_8->setText(QApplication::translate("godsInformation", "DESCRIPTION", 0));
        label_9->setText(QApplication::translate("godsInformation", "to destroy any opponent who crosses their paths . ", 0));
        label_10->setText(QApplication::translate("godsInformation", "There is little chance of beating them.", 0));
        menuGods_Info->setTitle(QApplication::translate("godsInformation", "Gods Info", 0));
    } // retranslateUi

};

namespace Ui {
    class godsInformation: public Ui_godsInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GODSINFORMATION_H
