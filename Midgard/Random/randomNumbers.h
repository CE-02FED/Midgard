
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
    static void* fill(void* var);
    static RandomNumbers* instancia;
    Vector<int>* _numeros;
    int* _posActual;
    Arduino* _arduino;

};

#endif /* RANDOMNUMBERS_ */
