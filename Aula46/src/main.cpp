#include <Arduino.h>
/*
#define pinLed 15

//prototipo da funcao

void piscaLed(uint8_t);

void setup() {
  pinMode(pinLed,OUTPUT);
}

void loop() {
  piscaLed(pinLed);
}


void piscaLed(uint8_t pin){
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
  delay(500);
}
*/

//exercicio = criar uma funcao com 3 parametros, a, b, e c, vai calcular uma equecao do segundo grau

int equacaoSegundoGrau(int, int, int);

void setup()
{
  Serial.begin(9600);
  int raizDaFuncao = equacaoSegundoGrau(1, 5, 6);
  Serial.print(raizDaFuncao);
}

void loop()
{

}

int equacaoSegundoGrau(int a, int b, int c)
{
  int delta = b * b - (4 * a * c);
  int resultado = ((- b + sqrt(delta)) / 2 * a);
  return resultado;
}