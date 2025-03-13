#include <LiquidCrystal_I2C.h>

// C++ code
// data:12/03/2025
// Julia Franca Iglesias

// Projeto: cada botao tem que ligar seu respectivo led, ao 
//  clicar no botaoA liga o ledA, clica denovo desliga, e tem 
//  que ir mostrando o estado de cada botao no display.

LiquidCrystal_I2C lcd (0x27, 16, 2);

const int pinBotaoA = 10;
const int pinLedA = 13;
const int pinBotaoB = 6;
const int pinLedB = 2;
const int pinBotaoC = 11;
const int pinLedC = 8;

// logica = se o estado anterior do botao for 0 e o atual for 1 
//  ele tem que alterar o estado do led

void setup()
{
  pinMode(pinBotaoA, INPUT);
  pinMode(pinLedA, OUTPUT);
  pinMode(pinBotaoB, INPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinBotaoC, INPUT);
  pinMode(pinLedC, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.home();//lcd.setCursor(0,0);
  
  // escrita inicial de todos desligados:
  
  lcd.setCursor(0,0);
  lcd.print("LedA OFF ");
  lcd.setCursor(0,1);
  lcd.print("LedB OFF");
  lcd.setCursor(10,0);
  lcd.print("LedC   ");
  lcd.setCursor(10,1);
  lcd.print("OFF ");
}

void loop()
{
  
  // LOGICA BOTAO A
  
  bool estadoBotaoA = digitalRead(pinBotaoA);
  static bool estadoLedA = 0;
  static bool estadoAnteriorBotaoA = 0; 
  
  if (!estadoBotaoA && estadoAnteriorBotaoA){
    estadoLedA = !estadoLedA;
    digitalWrite(pinLedA, estadoLedA);
    lcd.setCursor(0,0);
    
    if(estadoLedA)lcd.print("LedA ON  ");
    else lcd.print("LedA OFF ");
  }
    
estadoAnteriorBotaoA = estadoBotaoA;
  
  // LOGICA BOTAO B
  
  bool estadoBotaoB = digitalRead(pinBotaoB);
  static bool estadoLedB = 0;
  static bool estadoAnteriorBotaoB = 0; 
  
  if (!estadoBotaoB && estadoAnteriorBotaoB){
    estadoLedB = !estadoLedB;
    digitalWrite(pinLedB, estadoLedB);
    lcd.setCursor(0,1);
    
    if(estadoLedB)lcd.print("LedB ON  ");
    else lcd.print("LedB OFF");
  }
  
estadoAnteriorBotaoB = estadoBotaoB;

  // LOGICA BOTAO C
  
  bool estadoBotaoC = digitalRead(pinBotaoC);
  static bool estadoLedC = 0;
  static bool estadoAnteriorBotaoC = 0; 
  
  if (!estadoBotaoC && estadoAnteriorBotaoC){
    estadoLedC = !estadoLedC;
    digitalWrite(pinLedC, estadoLedC);
    lcd.setCursor(10,0);
    lcd.print("LedC   ");
    
    if(estadoLedC){
      lcd.setCursor(10,1);
      lcd.print("ON  ");
    }
    else {
      lcd.setCursor(10,1);
      lcd.print("OFF ");
    }
  }
  
estadoAnteriorBotaoC = estadoBotaoC;
  
}

