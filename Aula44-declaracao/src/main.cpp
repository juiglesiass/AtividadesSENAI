#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// **** INSTANCIAS DE OBJETOS ****
LiquidCrystal_I2C lcd(0x27,20,4);

  byte customChar[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

void setup()
{
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    lcd.print("eu te amo Pedro ");

    lcd.createChar(0, customChar);
    lcd.setCursor(16,0);
    lcd.write((uint8_t)0);

    lcd.setCursor(0,1);
    lcd.print("feliz ");
    
    lcd.setCursor(7,1);
    lcd.print(" meses de");
    lcd.setCursor(0,2);
    lcd.print("namoro");

    for(int meses=0 ; meses<=8 ; meses++){
    lcd.setCursor(6,1);
    lcd.print(meses);
    delay(500);
    }



}

void loop()
{

}