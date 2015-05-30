/********************************************************************************
** Form generated from reading UI file 'informationindividual.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONINDIVIDUAL_H
#define UI_INFORMATIONINDIVIDUAL_H

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

class Ui_informationIndividual
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *IdFather;
    QLabel *IdMother;
    QLabel *Fitness;
    QLabel *fotoPadre;
    QLabel *fotoMadre;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMidgard;

    void setupUi(QMainWindow *informationIndividual)
    {
        if (informationIndividual->objectName().isEmpty())
            informationIndividual->setObjectName(QStringLiteral("informationIndividual"));
        informationIndividual->resize(260, 454);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(false);
        informationIndividual->setFont(font);
        centralwidget = new QWidget(informationIndividual);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 280, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 330, 91, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 380, 71, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 10, 221, 41));
        IdFather = new QLabel(centralwidget);
        IdFather->setObjectName(QStringLiteral("IdFather"));
        IdFather->setGeometry(QRect(130, 280, 91, 17));
        IdMother = new QLabel(centralwidget);
        IdMother->setObjectName(QStringLiteral("IdMother"));
        IdMother->setGeometry(QRect(130, 330, 81, 17));
        Fitness = new QLabel(centralwidget);
        Fitness->setObjectName(QStringLiteral("Fitness"));
        Fitness->setGeometry(QRect(130, 380, 81, 17));
        fotoPadre = new QLabel(centralwidget);
        fotoPadre->setObjectName(QStringLiteral("fotoPadre"));
        fotoPadre->setGeometry(QRect(20, 60, 91, 181));
        fotoPadre->setPixmap(QPixmap(QString::fromUtf8("../../Escritorio/knight.png")));
        fotoMadre = new QLabel(centralwidget);
        fotoMadre->setObjectName(QStringLiteral("fotoMadre"));
        fotoMadre->setGeometry(QRect(130, 80, 91, 141));
        fotoMadre->setPixmap(QPixmap(QString::fromUtf8("../../Escritorio/wizardWoman.png")));
        informationIndividual->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(informationIndividual);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        informationIndividual->setStatusBar(statusbar);
        menuBar = new QMenuBar(informationIndividual);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 260, 27));
        menuMidgard = new QMenu(menuBar);
        menuMidgard->setObjectName(QStringLiteral("menuMidgard"));
        informationIndividual->setMenuBar(menuBar);

        menuBar->addAction(menuMidgard->menuAction());

        retranslateUi(informationIndividual);

        QMetaObject::connectSlotsByName(informationIndividual);
    } // setupUi

    void retranslateUi(QMainWindow *informationIndividual)
    {
        informationIndividual->setWindowTitle(QApplication::translate("informationIndividual", "MainWindow", 0));
        label->setText(QApplication::translate("informationIndividual", "id Father:", 0));
        label_2->setText(QApplication::translate("informationIndividual", "id mother:", 0));
        label_3->setText(QApplication::translate("informationIndividual", "Fitness:", 0));
        label_4->setText(QApplication::translate("informationIndividual", "INDIVIDUAL INFORMATION", 0));
        IdFather->setText(QApplication::translate("informationIndividual", "TextLabel", 0));
        IdMother->setText(QApplication::translate("informationIndividual", "TextLabel", 0));
        Fitness->setText(QApplication::translate("informationIndividual", "TextLabel", 0));
        fotoPadre->setText(QString());
        fotoMadre->setText(QString());
        menuMidgard->setTitle(QApplication::translate("informationIndividual", "Midgard", 0));
    } // retranslateUi

};

namespace Ui {
    class informationIndividual: public Ui_informationIndividual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATIONINDIVIDUAL_H
