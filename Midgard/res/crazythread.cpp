#include "crazythread.h"

CrazyThread::CrazyThread(void *func, void *arg)
{
    _func = func;
    _arg = arg;
    _thread = new pthread_t;
    run();
}

CrazyThread::~CrazyThread()
{

}

void CrazyThread::run()
{
    pthread_create(_thread, nullptr, (void*(*)(void*))_func, _arg);
    //pthread_create(_thread, nullptr, _func, _arg);
}


void CrazyThread::join()
{
    pthread_join(*_thread, NULL);
}

std::string CrazyThread::getId()
{
    return _id;
}

void CrazyThread::setId(std::string id)
{
    _id = id;
}
