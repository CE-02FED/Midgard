#include "arduino.h"

Arduino::Arduino(int pSpeed) {
    _serial = new SerialStream();
    _serial->Open(ARDUINO_PATH);
    switch (pSpeed) {
        case 9600:
            _serial->SetBaudRate(SerialStreamBuf::BAUD_9600);
            break;
        case 19200:
            _serial->SetBaudRate(SerialStreamBuf::BAUD_19200);
            break;
    }
    _serial->SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
    _serial->SetParity(SerialStreamBuf::PARITY_NONE);
    _serial->SetNumOfStopBits(1);
    _serial->SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);
    if (!_serial->good()) {
        perror("Error arduino connection.");
    }
}

Arduino::~Arduino() {
    close();
    free(_serial);
}

string Arduino::read() {
    char _charActualSerial;
    *_serial >> _charActualSerial;
    string _salida = "0";
    while (_charActualSerial != '#') {
        _salida += _charActualSerial;
        *_serial >> _charActualSerial;
    }
    return _salida;
}

void Arduino::write(string pMsg) {
    while (1) {
        struct timespec timer, timer2;
        timer.tv_sec = 3;
        timer.tv_nsec = 0;

        nanosleep(&timer, &timer2);
        break;
    }
    cout << "msg enviar" << endl;

    *_serial << pMsg;
    cout << "msg enviado" << endl;
}

void Arduino::close() {
    _serial->Close();
}
