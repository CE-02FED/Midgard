#include "mythread.h"
/**
 * @brief vThread::vThread
 * @param func funcion
 * @param arg argumento
 */
MyThread::MyThread(void *func, void *arg)
{
    _func = func;
    _arg = arg;
    _thread = new pthread_t;
    run();
}

/**
 * @brief vThread::~vThread
 */
MyThread::~MyThread()
{

}

/**
 * @brief vThread::run
 */
void MyThread::run()
{
    pthread_create(_thread, nullptr, (void*(*)(void*))_func, _arg);

}

/**
 * @brief vThread::join
 */
void MyThread::join()
{
    pthread_join(*_thread, nullptr);
}

/**
 * @brief vThread::getId
 * @return un string que es ID
 */
std::string MyThread::getId()
{
    return _id;
}

/**
 * @brief vThread::setId
 * @param id ID jeje
 */
void MyThread::setId(std::string id)
{
    _id = id;
}
