#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <Bounce2.h>
#include <ezTime.h>
#include "internet.h"

#define pinLed 2
#define pinBotao 0

WiFiClient espClient;
PubSubClient client(espClient);
Bounce botao = Bounce();
Timezone tempo;

const char *mqtt_server = "broker.hivemq.com"; //endereco do broker, pode ser um ip, nds
const int mqtt_port = 1883; //porta de comunicacao sem seguranca
const char *mqtt_id = "esp32-senai134-julia"; //id = nome do dispositivo
const char *mqtt_topic_sub = "senai134/mesa03/esp_inscrito"; //o esp esta ouvindo este topico, 
const char *mqtt_topic_pub = "senai134/mesa03/esp_publicando"; //o esp publica mensagens

void callback(char *, byte *, unsigned int);
void mqttConnect(void);
void pisca();

int tempoEspera = 0;

bool estadoLed = false;
bool modoPisca = false;
bool envioMqtt = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);

  botao.attach(pinBotao, INPUT_PULLUP);
  botao.interval(50);

  conectaWiFi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  pinMode(0, INPUT_PULLUP);
}

void loop() 
{
  botao.update();
  checkWiFi();

  if(!client.connected())
  {
    mqttConnect();
  }

  client.loop(); // envia e recebe mensagens

  static unsigned long tempoAnterior = 0;
  unsigned long tempoAtual = millis();

  JsonDocument doc;
  String mensagem;

  if (botao.changed())
  {
    Serial.println("botao");

    doc["botao"] = botao.read();
    doc["timestamp"] = tempo.now();
    envioMqtt = true;
  }

  if(envioMqtt)
  {
    serializeJson(doc, mensagem);
    Serial.println(mensagem);
    client.publish(mqtt_topic_pub, mensagem.c_str());
    envioMqtt = false;
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

  JsonDocument doc;
  deserializeJson(doc,mensagem);

  if (!doc["estadoLed"].isNull())
  {
    estadoLed = doc["estadoLed"];
    modoPisca = 0;
  }

  if(!doc["modoPisca"].isNull())
  {
    modoPisca = doc["modoPisca"];
  }

  if(!doc["velocidade"].isNull())
  {
    tempoEspera = doc["velocidade"];
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
    if(agora - ultimaMudanca > tempoEspera)
      {
        estadoLed = !estadoLed;
        ultimaMudanca = agora;
      }
  }

  digitalWrite(pinLed, estadoLed);
}