#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "internet.h"
#define pinLed 2

WiFiClient espClient;
PubSubClient client(espClient);

const char *mqtt_server = "broker.hivemq.com"; //endereco do broker, pode ser um ip, nds
const int mqtt_port = 1883; //porta de comunicacao sem seguranca
const char *mqtt_id = "esp32-senai134-julia"; //id = nome do dispositivo
const char *mqtt_topic_sub = "senai134/mesa03/esp_inscrito"; //o esp esta ouvindo este topico, 
const char *mqtt_topic_pub = "senai134/mesa03/esp_publicando"; //o esp publica mensagens

void callback(char *, byte *, unsigned int);
void mqttConnect(void);
void pisca();

bool estadoLed = false;
bool modoPisca = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  conectaWiFi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() 
{
  checkWiFi();

  if(!client.connected())
  {
    mqttConnect();
  }

  client.loop(); // envia e recebe mensagens

  static unsigned long tempoAnterior = 0;
  unsigned long tempoAtual = millis();

  if(tempoAtual - tempoAnterior > 3000)
  {
    client.publish(mqtt_topic_pub, "Ola, Mundo"); // manda ola mundo a cada 3s no topico de publicar
    tempoAnterior = tempoAtual;
  }
  
  pisca();

}



void callback(char *topic, byte *payLoad, unsigned int Length) //recebendo msg
{
  Serial.printf("mensagem recebida em %s:", topic);
  String mensagem = "";
  for (unsigned int i = 0; i < Length; i++)
  {
    char c = (char)payLoad[i];
    mensagem += c;
  }
  Serial.println(mensagem);

  mensagem.trim();
  mensagem.toLowerCase();
  if (mensagem == "liga")
  {
    estadoLed = true;
    modoPisca = false;

    Serial.println("Led Ligado");
  }

  else if (mensagem == "desliga")
  {
    estadoLed = false;
    modoPisca = false;

    Serial.println("Led Desligado");
  }

  else if (mensagem == "pisca")
  {
    modoPisca = true;

    Serial.println("Led Piscando");
  }

  else
  {
    Serial.println("Comando Nao Reconhecido");
  }
}

void mqttConnect()
{
  while (!client.connected())
  {
    Serial.println("conectando ao MQTT...");

    if (client.connect(mqtt_id))
    {
      Serial.println("Conectado com sucesso");
      client.subscribe(mqtt_topic_sub);
    }

    else
    {
      Serial.print("falha, rc=");
      Serial.println(client.state());
      Serial.println("tentando novamente em 5 segundos");
      delay(5000);
    }
    
  }
  
}

void pisca()
{
  static unsigned long ultimaMudanca = 0;
  unsigned long agora = millis();

  if (modoPisca)
  {
    if(agora - ultimaMudanca > 500)
      {
        estadoLed = !estadoLed;
        ultimaMudanca = agora;
      }
  }

  digitalWrite(pinLed, estadoLed);
}