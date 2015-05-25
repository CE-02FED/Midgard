#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtMultimedia>
#include <QMediaPlaylist>
#include "GuiFacade.h"

namespace Ui {
class MainWindow;
#include "Scene.h"
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_Quit_clicked();

private:
    Ui::MainWindow* ui;
    QMediaPlayer* player;
    QMediaPlayer* buttonSound;
    QMediaPlaylist* playlist;

};

#endif // MAINWINDOW_H
