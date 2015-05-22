#include <QApplication>
#include "Scene.h"
//#include "mythread.h"
class MyThread;

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   srand(time(0));
   Scene* scene;
   scene = new Scene();
   scene->show();

   //MyThread* _thread = new MyThread((void*)scene->start,nullptr);



   return a.exec();
}
