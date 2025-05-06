#include <Arduino.h>

#define pinLed 2

void setup() {
  Serial.begin(9600);
  Serial.print("Comunicacao Serial Iniciada \n");
  pinMode(pinLed,OUTPUT);
}

void loop() {

  static bool estadoLed = false;
  static bool piscaLed = false;
  static int tempo = 500;

  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;

  if(Serial.available())
  {
    String msg = Serial.readStringUntil('\n');
    msg.trim();

    if(msg.equals("liga"))
    {
      piscaLed = false;
      estadoLed = true;
    }

    else if (msg.equals("desliga"))
    {
      piscaLed = false;
      estadoLed = false;
    }

    else if (msg.equals("pisca"))
    {
      piscaLed = true;
    }

    else if(msg.equals("rap"))
    {
      tempo -= 100;
      Serial.println(tempo);
      if(tempo < 50) 
      {
      tempo = 50;
      Serial.print("velocidade maxima atingida");
      }
    }

    else if(msg.equals("dev"))
    {
      tempo += 100;
      Serial.println(tempo);
      if(tempo > 1000) 
      {
      tempo = 1000;
      Serial.print("velocidade minima atingida");
      }
    }

      if(msg.startsWith("vel = "))
    {
      int tamanho = msg.length();
      String extracao = msg.substring(6, tamanho);
      int valorVelocidade = extracao.toInt();

      if(valorVelocidade >=0 && valorVelocidade <= 100)
      {
      tempo = map(valorVelocidade, 0, 100, 1000, 50);
      }
      else 
      Serial.println("Valores aceitos apenas entre 0 e 100");
      
    }

  }


if(piscaLed)
  {
    if(tempoAtual - tempoInicial > tempo)
    {
      estadoLed = !estadoLed;
      tempoInicial = tempoAtual;
    }
  }

  digitalWrite(pinLed, estadoLed);
  
}
