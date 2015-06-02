#include "mainmenu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    player = new QMediaPlayer;

    playlist = new QMediaPlaylist;
    for(int i = 0; i < 10; i++)
    {
        playlist->addMedia(QUrl::fromLocalFile(QFileInfo("imagenes GUI/heaven-help-us.mp3").absoluteFilePath()));
    }
    playlist->setCurrentIndex(1);

    player->setPlaylist(playlist);
    player->setVolume(30);

    player->play();


    buttonSound = new QMediaPlayer;
    buttonSound->setMedia(QUrl::fromLocalFile(QFileInfo("imagenes GUI/button-40.wav").absoluteFilePath()));
    buttonSound->setVolume(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    this->buttonSound->play();

    Scene* scene;
    scene = new Scene();
    scene->show();

    GuiFacade* _guiFacade;
    _guiFacade = GuiFacade::getInstance();
    _guiFacade->runGui(scene);
    player->stop();

    this->close();

}

void MainWindow::on_Quit_clicked()
{
    this->buttonSound->play();
    exit(1);

}

