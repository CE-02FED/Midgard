
#ifndef RANDOMNUMBERS_
#define RANDOMNUMBERS_
#include "vector.h"
#include "arduino.h"
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

class RandomNumbers {
public:
    ~RandomNumbers();
    static RandomNumbers* getInstance();
    int get();
private:
    RandomNumbers();
    static RandomNumbers* instancia;
    Arduino* _arduino;

};

#endif /* RANDOMNUMBERS_ */
