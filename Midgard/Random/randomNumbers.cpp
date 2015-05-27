#define BITS_PER_SECOND 19200

#include "randomNumbers.h"

RandomNumbers* RandomNumbers::instancia = 0;
pthread_mutex_t mutex;

RandomNumbers* RandomNumbers::getInstance() {
    if (instancia == 0)
        instancia = new RandomNumbers();
    return instancia;
}

RandomNumbers::RandomNumbers() {
    _arduino = new Arduino(BITS_PER_SECOND);
    _arduino->write("check");
}

RandomNumbers::~RandomNumbers() {
    free(_arduino);
    free(instancia);
}

int RandomNumbers::get() {
    int _salida = stoi(_arduino->read());
    return _salida;
}
