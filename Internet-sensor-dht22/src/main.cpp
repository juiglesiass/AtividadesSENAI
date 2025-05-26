#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <ezTime.h>
#include "internet.h"

#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

WiFiClient espClient;
PubSubClient client(espClient);
Timezone tempo;


const char *mqtt_server = "broker.hivemq.com"; //endereco do broker, pode ser um ip, nds
const int mqtt_port = 1883; //porta de comunicacao sem seguranca
const char *mqtt_id = "esp32-senai134-julia"; //id = nome do dispositivo
const char *mqtt_topic_sub = "senai134/mesa03/esp_inscrito"; //o esp esta ouvindo este topico, 
const char *mqtt_topic_pub = "senai134/mesa03/esp_publicando"; //o esp publica mensagens

void callBack(char *, byte *, unsigned int);
void mqttConnect(void);

int tempoEspera = 0;

bool envioMqtt = false;

unsigned long ultimoEnvio = 0;
unsigned long intervaloEnvio = 3000;

void setup()
{
  Serial.begin(9600);
  conectaWiFi();
  dht.begin();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callBack);

  waitForSync();
  tempo.setLocation("America/Sao_Paulo");
}

void loop()
{
  float temp = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (isnan(temp) || isnan(umidade))
  {
    Serial.println("Erro ao ler o sensor");
    return;
  }

  checkWiFi();
  if (!client.connected())
    mqttConnect();

  client.loop();

  unsigned long agora = millis();
  if (agora - ultimoEnvio >= intervaloEnvio)
  {
    ultimoEnvio = agora;

    JsonDocument doc;
    doc["temperatura"] = temp;
    doc["umidade"] = umidade;
    doc["timeStamp"] = tempo.now();
    envioMqtt = true;
    

    String mensagem;
    serializeJson(doc, mensagem);

    Serial.print("Enviando dados MQTT: ");
    Serial.println(mensagem);

    client.publish(mqtt_topic_pub, mensagem.c_str());
  }

}

void callBack(char *topic, byte *payLoad, unsigned int length)
{
  Serial.printf("Mensagem recebida em %s: ", topic);

  String mensagem = "";
  for (unsigned int i = 0; i < length; i++)
  {
    mensagem += (char)payLoad[i];
  }
  Serial.println(mensagem);

  JsonDocument doc;
  deserializeJson(doc, mensagem);

    if (!doc["intervalo"].isNull())
  {
    intervaloEnvio = doc["intervalo"];
  }
}

void mqttConnect(void)
{
  while (!client.connected())
  {
    Serial.println("Conectando ao MQTT...");

    if (client.connect(mqtt_id))
    {
      Serial.println("Conectado com sucesso");
      client.subscribe(mqtt_topic_sub);
    }
    else
    {
      Serial.print("Falha, rc = ");
      Serial.println(client.state());
      Serial.println("Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}
