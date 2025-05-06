#include <Arduino.h>
#include <BluetoothSerial.h>

int pinLed = 2;
void on();
void off();
void pisca();

// ESP MASTER  ************************************************************

BluetoothSerial SerialBT;

void setup() {
//ler o serial e imprimir no blutetooth e tem que ter uma variavel

  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  SerialBT.begin("masterDaRafa", true);

  // if (SerialBT.connect("slaveDaJu"))
  // {
  //   Serial.println("conectado ao Dispositivo com sucesso!");
  // }

  // else
  // {
  //   Serial.println("Deu ruim galera...");
  //   while (true); // trava o esp
  // }

}

void loop() {

  // String leitura = SerialBT.read();


  if(SerialBT.available())
  {
    String mensagem = SerialBT.readStringUntil('\r');
    Serial.printf("Mensagem recebida: %s\n\r", mensagem);
    
    if (mensagem.equals("on"))
    {
    on();
    }

     if (mensagem.equals("off"))
    {
    off();
    }

    if (mensagem.equals("pisca"))
    {
    pisca();
    }

  }

// Envia mensagem
  if (Serial.available()) 
  {
    String msgEnviada = Serial.readStringUntil('\n');
    SerialBT.println(msgEnviada);
  }

  // Recebe mensagem
  if (SerialBT.available()) 
  {
    String msgRecebida = SerialBT.readStringUntil('\n');
    Serial.printf("Mensagem recebida: %s", msgRecebida);
  }

}

void on() 
{
  digitalWrite(pinLed, HIGH);
}

void off()
{
  digitalWrite(pinLed, LOW);
}

void pisca()
{
  digitalWrite(pinLed, HIGH);
  delay(500);
  digitalWrite(pinLed, LOW);
  delay(500);

  digitalWrite(pinLed, HIGH);
  delay(500);
  digitalWrite(pinLed, LOW);
  delay(500);

  digitalWrite(pinLed, HIGH);
  delay(500);
  digitalWrite(pinLed, LOW);
  delay(500);
}