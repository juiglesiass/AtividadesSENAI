#include <Arduino.h>
#include <ezTime.h>
#include "internet.h"

Timezone tempo;

void odirlei();

void setup() 
{
  Serial.begin(9600);

  conectaWiFi();

  waitForSync(); //esperar para sincronizar, se nao sincronizar com a hora vai aparecer coisa errada
  tempo.setLocation("America/Sao_Paulo");
}

void loop() 
{
  checkWiFi();

  Serial.println(tempo.dateTime()); //dia da semana (sunday-saturday) + dia-mes-ano + hora-min-seg + fuso-horario
  Serial.println(tempo.day()); //dia atual do mes 
  Serial.println(tempo.month()); //mes atual
  Serial.println(tempo.year()); //ano atual
  Serial.println(tempo.yearISO()); //ano atual ?
  Serial.println(tempo.dayOfYear()); //dia do ano
  Serial.println(tempo.hour()); //hora atual
  Serial.println(tempo.hourFormat12()); //hora atual no formato 12horas (americano?)
  Serial.println(tempo.minute()); //minutos
  Serial.println(tempo.second()); //segundos
  Serial.println(tempo.getPosix()); //fuso horario
  Serial.println(tempo.isAM()); //antes do meio-dia? sim=1 nao=0
  Serial.println(tempo.isPM()); //depois do meio-dia? sim=1 nao=0
  Serial.println(tempo.now()); //time stump (segundos desde 1970)
  Serial.println(tempo.ms()); //milisegundos
  Serial.println(tempo.weekday()); //dia da semana 1-7
  odirlei();
}

void odirlei()
{
  delay(2000);
}