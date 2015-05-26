#ifndef ARDUINO_H_
#define ARDUINO_H_
#include <stdlib.h>
#include <SerialStream.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace std;
using namespace LibSerial;

class Arduino {
public:
    Arduino(int pSpeed);
    ~Arduino();
    string read();
    void write(string pMsg);
    void close();
private:
    SerialStream* _serial;
};

#endif /* ARDUINO_H_ */
