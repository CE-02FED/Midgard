#include "randomNumbers.h"

RandomNumbers* RandomNumbers::instancia = 0;
pthread_mutex_t mutex;

RandomNumbers* RandomNumbers::getInstance() {
    if (instancia == 0)
        instancia = new RandomNumbers();
    return instancia;
}

RandomNumbers::RandomNumbers() {
    _arduino = new Arduino(19200);
    _arduino->write("check");
}

RandomNumbers::~RandomNumbers() {
    pthread_mutex_lock(&mutex);
    free(_arduino);
    free(instancia);
    pthread_mutex_unlock(&mutex);
}

int RandomNumbers::get() {
    int _salida = stoi(_arduino->read());
    return _salida;
}
