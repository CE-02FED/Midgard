#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define BAUD_RATE 9600
#define ANALOG_PIN 0
#define LARGO 16
#define ANCHO 2

//Variables globales
bool enviar = false;

void setup() {
  //Inicializar LCD
  lcd.begin(LARGO,ANCHO);
  printInicio();

  //Inicializa Serial
  Serial.begin(BAUD_RATE);
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
  int _valorPin = analogRead(ANALOG_PIN);

  static int _contador = 0;
  static byte _salida = 0;
  if(_valorPin) {
    _salida = (_salida << 1) | 0x01;
  }
  else {
    _salida = (_salida << 1);
  }

  _contador++;
  _contador %= 8;
  if(_contador == 0) {
    if(enviar) {
      Serial.println(_salida);
      lcd.print(_salida);
    }
    _salida = 0;
  }

  if(!Serial.available()){  //Esperando conexion serial
    /*******************/
  }
  else {
    String info = readSerial();
    if(info == "a"){
      enviar = true;
    }
    else {
      Serial.flush();
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