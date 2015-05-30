#ifndef MYTHREAD_H
#define MYHREAD_H
#include <iostream>
#include <pthread.h>
#include "string"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

class MyThread{
private:
    std::string _id;
    void* _func;
    void* _arg;
    pthread_t* _thread;

public:
    MyThread(void *func, void *arg);

    ~MyThread();

    std::string getId();
    void setId(std::string id);
    void run();
    void join();
};

#endif

