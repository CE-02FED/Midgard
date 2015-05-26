#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define BAUD_RATE 19200
#define ANALOG_PIN 0
#define LARGO 16
#define ANCHO 2
#define BYTE 256

//Variables globales
bool enviar = false;
unsigned int binarios[BYTE];
bool inicializar = true;
unsigned int contadorCalibracion = 0;

void setup() {
  //Inicializar lcd
  lcd.begin(LARGO,ANCHO);
  printInicio();
  
  //Inicializa Serial
  Serial.begin(BAUD_RATE);
  //Serial.flush();
  //Serial.println("EC");
}

//Imprime esperando conexion
void printInicio(){
  lcd.setCursor(0,0);
  lcd.print("Esperando");
  lcd.setCursor(2,1);
  lcd.print("conexion...");
  lcd.setCursor(0,0);
}


void loop() {
  byte _tendencia;
  int _valorPin = analogRead(ANALOG_PIN);
  byte _valorByte = _valorPin >> 2;
  bool _byteProcesado;
  
  if (contadorCalibracion >= 1000) {
    _tendencia = encontrarTendencia();
    inicializar = false;
  }
  if (inicializar) {
    calibrar(_valorByte);
    contadorCalibracion++;
  }
  else {
    _byteProcesado = (_valorByte < _tendencia) ? 1:0;
    generarRandom(_byteProcesado);
  }
  
  if(!Serial.available()){  //Esperando conexion serial
    /*******************/
  } 
  else {
    String info = readSerial();
    if(info == "check"){
      enviar = true;
    }     
  }
}

String readSerial(){
  String data = "";
  while(Serial.available()){
    data += Serial.readString();
  }
  return data;
}

/*********************************************************/
//Generar numero con bits
void generarRandom(byte pValor) {
  static bool _previo = 0;
  static bool _variar = 0;
  
  _variar = !_variar;
  if (_variar) {
    if(pValor == 1 && _previo == 0) {
      construirRandom(0);
    }
    else if (pValor == 0 && _previo == 1) {
      construirRandom(1);
    }
  }
  _previo = pValor;
}

void construirRandom(bool pValor) {
  static int _contadorByte = 0;
  static byte _salida = 0;
  
  if (pValor == 1) {
    _salida = (_salida << 1) | 0x01;
  }
  else {
    _salida = _salida << 1;
  }
  
  _contadorByte++;
  _contadorByte %= 8;
  if (_contadorByte == 0) {
    if(enviar) {
      String _salidaStr = String(_salida);
      _salidaStr += "#";
      Serial.println(_salidaStr);
      lcd.print(_salidaStr);
    }
    _salida = 0;
  }
}

//Calibrar generador
void calibrar(byte pValor) {
  binarios[pValor]++;
}

unsigned int encontrarTendencia() {
  unsigned long _mitad;
  unsigned long _total = 0;
  int _tendencia;
  
  for (_tendencia = 0; _tendencia < 256; _tendencia++) {
    _total += binarios[_tendencia];
  }
  
  _mitad = _total >> 1;
  _total = 0;
  for (_tendencia = 0; _tendencia < 256; _tendencia++) {
    _total += binarios[_tendencia];
    if (_total > _mitad) break;
  }
  return _tendencia;
}
