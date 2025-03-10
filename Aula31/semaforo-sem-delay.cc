// C++ code
// Projeto: Fazer um semáforo sem usar o delay
// Data:07/03/2025

#define ledRed 13
#define ledYellow 11
#define ledGreen 8
#define tempo5s 5000 //verde
#define tempo2s 2000 //amarelo 
#define tempo3s 3000 //red 

unsigned long tempoAtual;
unsigned long tempoInicial = 0;
char faseSemaforo = 0;

  
void setup()
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
 
}

void loop()
{
    tempoAtual = millis();
  
  if (faseSemaforo == 0){
    digitalWrite(ledGreen,1);
    digitalWrite(ledYellow,0);
    digitalWrite(ledRed,0);
  
  if (tempoAtual - tempoInicial > tempo5s){
     faseSemaforo = 1;
     tempoInicial = tempoAtual;
     }
  }
      
  else if (faseSemaforo == 1){
     digitalWrite(ledGreen,0);
     digitalWrite(ledYellow,1);
     digitalWrite(ledRed,0);
    
  if(tempoAtual - tempoInicial > tempo2s){
     faseSemaforo = 2;
     tempoInicial = tempoAtual;
     }
  }
      
  else if (faseSemaforo == 2){
     digitalWrite(ledGreen,0);
     digitalWrite(ledYellow,0);
     digitalWrite(ledRed,1);
  
     if(tempoAtual - tempoInicial > tempo3s){
     faseSemaforo = 0;
     tempoInicial = tempoAtual;
     }
  }
}