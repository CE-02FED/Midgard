#define CANTIDAD_NUMEROS 100
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
    _numeros = new Vector<int>(CANTIDAD_NUMEROS);
    _numeros->llenarMatriz(0);
    _posActual = new int(0);
    pthread_t _fillThread;
    //pthread_create(&_fillThread, 0, fill, 0);
}

RandomNumbers::~RandomNumbers() {
    pthread_mutex_lock(&mutex);
    free(_arduino);
    free(_numeros);
    free(instancia);
    pthread_mutex_unlock(&mutex);
}

int RandomNumbers::get() {
//	pthread_mutex_lock(&mutex);
//	int _salida = *(*_numeros)[*_posActual];
//	while (_salida == 0) {
//		pthread_mutex_unlock(&mutex);
//		struct timespec timer, timer2;
//		timer.tv_sec = 1;
//		timer.tv_nsec = 0;
//		nanosleep(&timer, &timer2);
//		pthread_mutex_lock(&mutex);
//		_salida = *(*_numeros)[*_posActual];
//	}
//	pthread_mutex_lock(&mutex);
//	*(*_numeros)[*_posActual] = 0;
//	(*_posActual)++;
//
//	if (*_posActual == _numeros->lenght())
//		*_posActual = 0;
//
//	pthread_mutex_unlock(&mutex);
    int _salida = stoi(_arduino->read());
    return _salida;
}

void* RandomNumbers::fill(void* var) {
    Vector<int>* _ptrNumeros = instancia->_numeros;
    Arduino* _prtArduino = instancia->_arduino;
    int _posicion;
    int _ultimaPosicionActualizada = 0;
    int _porcentaje = (_ptrNumeros->lenght()) * 0.2;
    int _contador = 0;

    while (true) {
        cout << "fill" << endl;

        pthread_mutex_lock(&mutex);

        for (_posicion = _ultimaPosicionActualizada; _posicion < _ptrNumeros->lenght(); _posicion++) {
            if (*(*_ptrNumeros)[_posicion] == 0) {
                int res = stoi(_prtArduino->read());
                *(*_ptrNumeros)[_posicion] = res;
            }
            else {
                break;
            }

            if (_contador != _porcentaje)
                _contador++;
            else
                break;

        }
        pthread_mutex_unlock(&mutex);

        _ultimaPosicionActualizada = _posicion;
        if (_ultimaPosicionActualizada == _ptrNumeros->lenght() - 1) {
            _ultimaPosicionActualizada = 0;
        }

        struct timespec timer, timer2;
        timer.tv_sec = 1;
        timer.tv_nsec = 0;
        nanosleep(&timer, &timer2);

    }
    return 0;
}
