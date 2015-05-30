/********************************************************************************
** Form generated from reading UI file 'puebloinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUEBLOINFORMATION_H
#define UI_PUEBLOINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_puebloInformation
{
public:
    QWidget *centralwidget;
    QLabel *title;
    QLabel *labelImage;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *nameTown;
    QLabel *labelFittest;
    QLabel *amountLabel;
    QLabel *label_4;
    QLabel *labelWorstFitness;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *puebloInformation)
    {
        if (puebloInformation->objectName().isEmpty())
            puebloInformation->setObjectName(QStringLiteral("puebloInformation"));
        puebloInformation->resize(439, 495);
        centralwidget = new QWidget(puebloInformation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        title = new QLabel(centralwidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(40, 20, 271, 51));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(true);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        title->setFont(font);
        title->setMouseTracking(false);
        labelImage = new QLabel(centralwidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(40, 80, 351, 131));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 250, 131, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Kinnari"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 300, 121, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 360, 191, 31));
        label_3->setFont(font1);
        nameTown = new QLabel(centralwidget);
        nameTown->setObjectName(QStringLiteral("nameTown"));
        nameTown->setGeometry(QRect(240, 260, 141, 21));
        labelFittest = new QLabel(centralwidget);
        labelFittest->setObjectName(QStringLiteral("labelFittest"));
        labelFittest->setGeometry(QRect(240, 310, 141, 21));
        amountLabel = new QLabel(centralwidget);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(240, 360, 151, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 410, 111, 17));
        label_4->setFont(font1);
        labelWorstFitness = new QLabel(centralwidget);
        labelWorstFitness->setObjectName(QStringLiteral("labelWorstFitness"));
        labelWorstFitness->setGeometry(QRect(240, 410, 111, 17));
        puebloInformation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(puebloInformation);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 439, 25));
        puebloInformation->setMenuBar(menubar);
        statusbar = new QStatusBar(puebloInformation);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        puebloInformation->setStatusBar(statusbar);

        retranslateUi(puebloInformation);

        QMetaObject::connectSlotsByName(puebloInformation);
    } // setupUi

    void retranslateUi(QMainWindow *puebloInformation)
    {
        puebloInformation->setWindowTitle(QApplication::translate("puebloInformation", "MainWindow", 0));
        title->setText(QApplication::translate("puebloInformation", "TOWN INFORMATION", 0));
        labelImage->setText(QApplication::translate("puebloInformation", "TextLabel", 0));
        label->setText(QApplication::translate("puebloInformation", "Town Name:", 0));
        label_2->setText(QApplication::translate("puebloInformation", "Fittest: ", 0));
        label_3->setText(QApplication::translate("puebloInformation", "Amount People:", 0));
        nameTown->setText(QApplication::translate("puebloInformation", "TextLabel", 0));
        labelFittest->setText(QApplication::translate("puebloInformation", "TextLabel", 0));
        amountLabel->setText(QApplication::translate("puebloInformation", "TextLabel", 0));
        label_4->setText(QApplication::translate("puebloInformation", "Worst Fitness:", 0));
        labelWorstFitness->setText(QApplication::translate("puebloInformation", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class puebloInformation: public Ui_puebloInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUEBLOINFORMATION_H
