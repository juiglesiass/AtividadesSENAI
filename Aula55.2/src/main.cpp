#include <Arduino.h>
#define pinLed 2

//INACABADO***************************

int ledEscolher [4]= {1,2,3,4};
int pinLeds[1] = {1};

int intensidade = 0;
String palavra = "";

void setup() 
{
  Serial.begin(9600);
  Serial.println("Digite o Led que deseja modificar: (1, 2, 3 ou 4)");

  for(int i=0 ; i<=4 ; i++){
  pinMode(pinLeds[i], OUTPUT);}
}

void loop() {
  if (Serial.available())
  {
    char caractere = Serial.read();

    if(caractere == '\n')
    {
      Serial.println(palavra);
      if (palavra.equals(pinLeds))
      {
        digitalWrite(pinLeds, HIGH);
        Serial.println("Led ");
        Serial.print(pinLeds);
        Serial.print(" ligado");
      }
      else if (palavra.equals("desliga"))
      {
        digitalWrite(pinLed, LOW);
      }
      
      else
      {
        Serial.println("Comando nao reconhecido");
      }

      palavra = "";
     
     }

      else if(caractere != '\r')
      {
      palavra += caractere;
      }
  }
}