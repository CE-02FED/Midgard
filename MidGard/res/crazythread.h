#ifndef CRAZYTHREAD_H
#define CRAZYTHREAD_H

#include <pthread.h>
#include <string>


class CrazyThread;
class CrazyThread
{
private:
    std::string _id;
    void* _func;
    void *_arg;
    pthread_t * _thread;

public:
    CrazyThread(void *func, void *arg);

    ~CrazyThread();

    std::string getId();
    void setId(std::string id);
    void run();
    void join();
};

#endif // THREAD_H
