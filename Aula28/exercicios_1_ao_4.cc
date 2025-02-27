// C++ code
//Exercicios diversos
//data 26/02/2025

//(1)CONTROLE DE TEMPERATURA
float temperatura=31; //em m
#define ledRed 13

//(2)ALERTA DE BATERIA
int bateria=79; 
#define ledOrange 10

//(3)PROGRAMA QUE AJUSTA VALOR
float valor = 500;
float resultadoMap = 0;
float resultadoConstrain = 0;
#define ledBlue 7

//(4)ACENDA SE FOR PAR
int numero = 4;
int numeroFixo = 2;
int resultado = 0;
#define ledGreen 4

void setup(){
  
  //(1)CONTROLE DE TEMPERATURA
    pinMode(ledRed, OUTPUT);
  
    if(temperatura > 30) {
     digitalWrite(ledRed, HIGH);
  }
    else {
     digitalWrite(ledRed, LOW);
  }
  
  //(2)ALERTA DE BATERIA
    Serial.begin(9600);
    pinMode(ledOrange, OUTPUT);
   
    if(bateria >20 && bateria <80) {
     Serial.println("ALERTA-BATERIA ENTRE 20% E 80%");
  }
  
  //(3)PROGRAMA QUE AJUSTA VALOR
    pinMode(ledBlue, OUTPUT);
  
    resultadoMap = map(valor, 0, 1023, 0, 100);
    Serial.println(resultadoMap);
    resultadoConstrain = constrain(resultadoMap, 20, 80);
    Serial.println(resultadoConstrain);
  
    if (resultadoMap <20 || resultadoMap >80);
     digitalWrite(ledBlue, HIGH);
     Serial.print("O valor: ");
     Serial.print(resultadoMap);
     Serial.print(" excedeu os limites, valor reajustado para: ");
     Serial.print(resultadoConstrain);

  //(4)ACENDA SE FOR PAR
    pinMode(ledGreen, OUTPUT);
  
    resultado = numero%numeroFixo;
  
    if (resultado==0){
     digitalWrite(ledGreen, HIGH);
   }
}

 void loop(){
  
   //(2)ALERTA DE BATERIA
    if(bateria >20 && bateria <80){
     digitalWrite(ledOrange, HIGH);
     delay(500);
     digitalWrite(ledOrange, LOW);
     delay(500);
  } 
  
}