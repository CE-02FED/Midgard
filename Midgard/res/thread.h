#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
class Thread{

public:
    Thread(){}
     virtual ~ Thread(){}
 bool start()
   {
      return (pthread_create(&_thread, NULL, InternalThreadEntryFunc, this) == 0);
   }

 void stop()
    {
       (void) pthread_join(_thread, NULL);
    }
protected:
 virtual void goRun() = 0;
private:
 static void * InternalThreadEntryFunc(void * This) {((Thread *)This)->goRun(); return NULL;}

    pthread_t _thread;

};

#endif // THREAD_H
