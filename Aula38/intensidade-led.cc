#include <LiquidCrystal_I2C.h>

// C++ code
//

#define valorBotao1 0
#define valorBotao2 145
#define valorBotao3 329
#define valorBotao4 505
#define valorBotao5 741
#define pinLedA 11
#define pinLedB 10

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  
  pinMode(pinLedA,OUTPUT);
  pinMode(pinLedB,OUTPUT);
  
  lcd.setCursor(1,0);
  lcd.print("LED A OFF");
  lcd.setCursor(1,1);
  lcd.print("LED B OFF");
}


void loop()
{ 
 
  static bool posicao = 0;
  static bool estadoLedA = 0;
  static bool estadoLedB = 0;
  static bool estadoAnteriorLed = 0;
  static byte intensidadeLedA = 0;
  static byte intensidadeLedB = 0;
  
  
  //-------------- TRATAMENTO BOTÕES ----------------
  
  static int valorAnteriorLeitura = 1023;
  int valorLeitura = analogRead(A0);
 
//BOTAO 1 
  
  if(valorAnteriorLeitura == 1023 and 
     valorLeitura == valorBotao1){

    posicao = 0;
  }
  
//BOTAO 2 
  
  else if(valorAnteriorLeitura == 1023 and
         valorLeitura >= valorBotao2 * 0.9 and
         valorLeitura <= valorBotao2 * 1.1){

    posicao = 1;
  }
 
//BOTAO 3 
  
   else if (valorAnteriorLeitura == 1023 and
     valorLeitura >= valorBotao3 * 0.9 and
     valorLeitura <= valorBotao3 * 1.1){
    
     if (!posicao && estadoLedA){
       if (intensidadeLedA>0)
         intensidadeLedA-=10;
       if (intensidadeLedA==0)
         estadoLedA = 0;
     } 
     if (posicao && estadoLedB){
       if (intensidadeLedB>0)
         intensidadeLedB-=10;
       if (intensidadeLedB==0)
         estadoLedB = 0;
     }
   }
  
//BOTAO 4 
  
   else if (valorAnteriorLeitura == 1023 and
     valorLeitura >= valorBotao4 * 0.9 and
     valorLeitura <= valorBotao4 * 1.1){
  
     if (!posicao && estadoLedA){
       if (intensidadeLedA<100)
       intensidadeLedA+=10;
     }
     if (posicao && estadoLedB){
       if (intensidadeLedB<100)
       intensidadeLedB+=10;
     }
   }
  
// BOTAO 5
  
  else if(valorAnteriorLeitura == 1023 and 
     valorLeitura >= valorBotao5 * 0.9 and
     valorLeitura <= valorBotao5 * 1.1){
    
    if(posicao == 0) {
       estadoLedA = !estadoLedA;
      	 if (estadoLedA && intensidadeLedA ==0)
           intensidadeLedA = 10;
    }  
    else {
       estadoLedB = !estadoLedB;
         if (estadoLedB && intensidadeLedB ==0)
           intensidadeLedB = 10;
     }
  }

  valorAnteriorLeitura = valorLeitura;
  
  
  // ----------- TRATAMENTO DISPLAY --------------
  
// SETAS
  
  if(!posicao){
  	lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(0,1);
    lcd.print(" ");
    }
    
  
  else {
  	lcd.setCursor(0,0);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print(">");
  } 
    
// MOSTRAR OS ESTADOS DOS LEDS 
  
     if(estadoLedA == 1){
        	lcd.setCursor(7,0);
          	lcd.print(intensidadeLedA);
       		lcd.print(" % ");
      }
      
     else{
            lcd.setCursor(7,0);
         	lcd.print("OFF  ");
      }	
    
     if(estadoLedB == 1){
        	lcd.setCursor(7,1);
          	lcd.print(intensidadeLedB);
       		lcd.print(" % ");
      }
      
      else{
            lcd.setCursor(7,1);
         	lcd.print("OFF  ");
      }
  
 
//------------- TRATAMENTO DOS LEDS -----------------
  
  	if (intensidadeLedA == 0){
    	digitalWrite(pinLedA, LOW); 
  	}
  	else analogWrite(pinLedA, intensidadeLedA);
  
  
  	if (intensidadeLedB == 0){
  	  digitalWrite(pinLedB, LOW); 
 	 }
 	else analogWrite(pinLedB, intensidadeLedB);
  
  if (estadoLedA == 0) digitalWrite(pinLedA, LOW); 
  else if (estadoLedB == 0) digitalWrite(pinLedB, LOW); 
    
}