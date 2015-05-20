
#include "Constants.h"


Constants* Constants::m_pInstancia = 0;
Constants* Constants::getInstance(){
    if (!m_pInstancia){
        m_pInstancia = new Constants();
    }
    return m_pInstancia;
}
Constants::Constants(){


}
string Constants::punteroToString(void* puntero){
    const void* address= static_cast<const void*>(puntero);
    stringstream ss;
    ss<<address;
    string name=ss.str();
    return name;
}

string Constants::integerToString(int entero){
     string cadena;
     stringstream ss;
     ss << entero;
     cadena = ss.str();
      return cadena;
}

