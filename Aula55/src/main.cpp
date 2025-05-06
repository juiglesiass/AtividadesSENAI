#include <Arduino.h>
#define pinLed 2


String palavra = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Digite algo no monitor Serial: ");
  pinMode(pinLed, OUTPUT);
}

void loop() {
  if (Serial.available())
  {
    char caractere = Serial.read();

    if(caractere == '\n')
    {
      Serial.println(palavra);
      if (palavra.equals("liga"))
      {
        digitalWrite(pinLed, HIGH);
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

      // if (caractere == 'L')
      // {
      //   digitalWrite(pinLed, HIGH);
      //   Serial.printf("Led ligado");
      // }
      
      // else if (caractere == 'D')
      // {
      //   digitalWrite(pinLed, LOW);
      //   Serial.printf("Led desligado");
      // }
      
      // else
      // {
      //   Serial.println("Digite L ou D");
      //   Serial.printf("Voce digitou %c \n \r", caractere);
      // }
      
  }
  
}
