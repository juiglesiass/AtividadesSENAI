#include <Arduino.h>

#define pinLed 15
#define botao 18

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(botao, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop()
{

  bool estadoAtualBotao = digitalRead(botao);
  static bool estadoAnteriorBotao = 1;
  static bool ultimaAcao = 1;

  static unsigned long tempoAnteriorDebounce = 0;
  unsigned long tempoAtual = millis();
  const unsigned long tempoDebounce = 50;

  static int contagem = 0;

  // marca quando uma mudanca de estado acontece
  if (estadoAtualBotao != estadoAnteriorBotao)
  {
    tempoAnteriorDebounce = tempoAtual;
  }

  // verifica se a mudanca de estado esta estavel a bastante tempo
  if ((tempoAtual - tempoAnteriorDebounce) > tempoDebounce)
  {
    // houve uma alteracao proposital do estado do botao?
    if (estadoAtualBotao != ultimaAcao)
    {
      ultimaAcao = estadoAtualBotao;
      if (!estadoAtualBotao)
      {
        // botao pressionado
        contagem++;
        Serial.println(contagem);
      }
      else
      {
      } // botao solto
    }
  }

  estadoAnteriorBotao = estadoAtualBotao;

  digitalWrite(pinLed, LOW);
}
