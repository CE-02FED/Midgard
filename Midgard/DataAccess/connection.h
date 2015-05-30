#ifndef CONNECTION_H
#define CONNECTION_H
#include "serversocket.h"
#include "SocketException.h"
#include "iostream"
#include "unistd.h"
#include "../logicFacade/LogicFacade.h"
#include "../res/thread.h"
#define port 9090
using namespace std;
class connection : public Thread {
public:
    connection();
protected:
    void goRun();
};

#endif // CONNECTION_H
