/*
Autor: Julia Iglesias
Nome programa: Semáforo com Cruzamento
Descricao: Segundo codigo no arduino, simulando semaforo real com cruzamento, falta adicionar o de pedestre
Data19/02/2025
*/

#define pinLedRed2 13
#define pinLedYellow2 12
#define pinLedGreen2 8
#define tempo5s 5000
#define tempo2s 2000
#define tempo3s 3000
#define pinLedRed1 6
#define pinLedYellow1 3
#define pinLedGreen1 2

void setup () //inicializa o arduino
{
	pinMode(pinLedRed1,OUTPUT); //define o pino 13 como saída
  	pinMode(pinLedYellow1,OUTPUT); //define o pino 12 como saída
  	pinMode(pinLedGreen1,OUTPUT); //define o pino 8 como saída
	pinMode(pinLedRed2,OUTPUT); //define o pino 6 como saída
  	pinMode(pinLedYellow2,OUTPUT); //define o pino 3 como saída
  	pinMode(pinLedGreen2,OUTPUT); //define o pino 2 como saída
}

void loop () //após o setup(código de inicialização), ativa a repetição dos códigos abaixo
{
	digitalWrite(pinLedGreen1,HIGH); //liga o pino 2 
    digitalWrite(pinLedRed2,HIGH); //liga o pino 13
    digitalWrite(pinLedRed1,LOW); //desliga o pino 6
  	digitalWrite(pinLedYellow2,LOW); //desliga o pino 12
  
  	delay(tempo3s); 
  
  	digitalWrite(pinLedGreen1,LOW); //desliga o pino 2
    digitalWrite(pinLedYellow1,HIGH); //liga o pino 3
    
  	delay(tempo2s);
  
    digitalWrite(pinLedRed2,LOW); //desliga o pino 13
  	digitalWrite(pinLedYellow1,LOW); //desliga o pino 3
  	digitalWrite(pinLedGreen2,HIGH); //liga o pino 8
    digitalWrite(pinLedRed1,HIGH); //liga o pino 6
    delay(tempo3s);
  
   	digitalWrite(pinLedGreen2,LOW); //desliga o pino 8
    digitalWrite(pinLedYellow2,HIGH); //liga o pino 12
  	digitalWrite(pinLedRed1,HIGH); //liga o pino 6
    delay(tempo2s); 
}