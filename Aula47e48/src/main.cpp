#include <Arduino.h>
#include <LiquidCrystal_I2C.H>

#define pinButtonLeft 19
#define pinButtonRight 15
#define pinLed 18

void cenario();
LiquidCrystal_I2C lcd(0x27, 20, 4);

int screenPosition[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int charPosition = 0;

byte leftChar[] = {B00000, B00000, B01110, B00001, B00001, B10001, B01110, B00000};
byte bolinha[] = {B00000, B00000, B01110, B10001, B10001, B10001, B01110, B00000};
byte estalacBig[] = {B11111, B11111, B01110, B01110, B00110, B00100, B00100, B00100};
byte estalacShort[] = {B11111, B01111, B00110, B00110, B00100, B00100, B00000, B00000};
byte batUp[] = {B00000, B00000, B10001, B01010, B00100, B00000, B00000, B00000};
byte batDown[] = {B00000, B00000, B00000, B00000, B00100, B01010, B10001, B00000};
byte caveira[] = {B00000, B00000, B01110, B10101, B11111, B01110, B00000, B00000};

void setup()
{
  Serial.begin(115200);
  pinMode(pinButtonLeft, INPUT_PULLUP);
  pinMode(pinButtonRight, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.createChar(0, leftChar);
  lcd.createChar(1, bolinha);
  lcd.createChar(2, estalacBig);
  lcd.createChar(3, estalacShort);
  lcd.createChar(4, batUp);
  lcd.createChar(5, batDown);
  lcd.createChar(6, caveira);

  cenario();

  lcd.setCursor(0, 2);
  lcd.print("c");
  lcd.setCursor(15, 2);
  lcd.print("*");
}

void loop()
{
  bool stateButtonRight = digitalRead(pinButtonRight);
  static bool previousStateButtonRight = 1;
  static bool previousActionRight = 1;
  bool stateButtonLeft = digitalRead(pinButtonLeft);
  static bool previousStateButtonLeft = 1;
  static bool previousActionLeft = 1;

  static unsigned long lastTimeChange = 0;
  static unsigned long lastTimeChange2 = 0;
  unsigned long time = millis();
  const unsigned long filterTime = 50;

  static bool powerUp = 0;

  unsigned long timeNow = millis();
  static unsigned long timeBegin = 0;
  static bool fly = 1;
  static int incrementoA = 7;
  static int incrementoB = 13;

  //! INICIA TRATAMENTO RIGHT BUTTON

  //* DETECTA MUDANÇA DE ESTADO BOTÃO
  if (stateButtonRight != previousStateButtonRight)
  {
    lastTimeChange = time; //* atualiza o tempo da mudança
  }

  //* verifica se o novo estado se manteve tempo o suficiente
  if ((time - lastTimeChange) > filterTime)
  {

    //* Verifica se ainda não processamos essa nova ação
    if (stateButtonRight != previousActionRight)
    {
      previousActionRight = stateButtonRight; //* atualiza o estado já processado para evitar ações repetidas enquanto o botão estiver no mesmo estado.

      if (!stateButtonRight and charPosition < 19)
      {
        if (!powerUp)
        {
          charPosition++;
          lcd.setCursor(charPosition - 1, 2);
          lcd.print(" ");
          lcd.setCursor(charPosition, 2);
          lcd.print("c");
        }

        else
        {
          charPosition++;
          lcd.setCursor(charPosition - 1, 2);
          lcd.print(" ");
          lcd.setCursor(charPosition, 2);
          lcd.write((uint8_t)1);
        }
      }

      else if (!stateButtonRight and charPosition == 19)
      {
        if (!powerUp)
        {
          lcd.setCursor(charPosition, 2);
          lcd.print(" ");
          charPosition = 0;
          lcd.setCursor(charPosition, 2);
          lcd.print("c");
        }

        else
        {
          lcd.setCursor(charPosition, 2);
          lcd.print(" ");
          charPosition = 0;
          lcd.setCursor(charPosition, 2);
          lcd.write((uint8_t)1);
        }
      }
    }
  }

  //! FIM TRATAMENTO RIGHT BUTTON

  //! INICIO TRATAMENTO LEFT BUTTON

  if (stateButtonLeft != previousStateButtonLeft)
  {
    lastTimeChange2 = time; //* atualiza o tempo da mudança
  }

  //* verifica se o novo estado se manteve tempo o suficiente
  if ((time - lastTimeChange2) > filterTime)
  {

    //* Verifica se ainda não processamos essa nova ação
    if (stateButtonLeft != previousActionLeft)
    {
      previousActionLeft = stateButtonLeft; //* atualiza o estado já processado para evitar ações repetidas enquanto o botão estiver no mesmo estado.

      if (!stateButtonLeft and charPosition > 0)
      {
        if (!powerUp)
        {
          charPosition--;
          lcd.setCursor(charPosition, 2);
          lcd.write((uint8_t)0);
          lcd.setCursor(charPosition + 1, 2);
          lcd.print(" ");
        }

        else
        {
          charPosition--;
          lcd.setCursor(charPosition, 2);
          lcd.write((uint8_t)1);
          lcd.setCursor(charPosition + 1, 2);
          lcd.print(" ");
        }
      }

      else if (!stateButtonLeft and charPosition == 0)
      {
        if (!powerUp)
        {
          lcd.setCursor(charPosition, 2);
          lcd.print(" ");
          charPosition = 19;
          lcd.setCursor(charPosition, 2);
          lcd.write((uint8_t)0);
        }

        else
        {
          lcd.setCursor(charPosition, 2);
          lcd.print(" ");
          charPosition = 19;
          lcd.setCursor(charPosition, 2);
          lcd.write((uint8_t)1);
        }
      }
    }
  }

  //! FIM TRATAMENTO LEFT BUTTON

  previousStateButtonRight = stateButtonRight;
  previousStateButtonLeft = stateButtonLeft;

  if (charPosition == 15 and powerUp == 0)
  {
    digitalWrite(pinLed, 1);
    powerUp = 1;
    lcd.setCursor(charPosition, 2);
    lcd.write((uint8_t)1);
  }

  //* INICIO TRATAMENTO MORCEGO

  if (timeNow - timeBegin > 500)
  {
    fly = !fly;
    timeBegin = timeNow;
  }

  if (fly)
  {
    lcd.setCursor(7, 1);
    lcd.write((uint8_t)4);
    lcd.setCursor(13, 1);
    lcd.write((uint8_t)5);
    lcd.setCursor(10, 2);
    lcd.write((uint8_t)4);
  }

  else
  {
    lcd.setCursor(7, 1);
    lcd.write((uint8_t)5);
    lcd.setCursor(13, 1);
    lcd.write((uint8_t)4);
    lcd.setCursor(10, 2);
    lcd.write((uint8_t)5);
  }
  //* FIM TRATAMENTO MORCEGO
  if (charPosition == 10 and !powerUp)
  {
    lcd.clear();
    for (int i = 2; i > 1; i++)
    {
      lcd.setCursor(5, 1);
      lcd.print("GAME OVER!");
      lcd.setCursor(7,2);
      lcd.write((uint8_t)6);
      lcd.setCursor(9,2);
      lcd.write((uint8_t)6);
      lcd.setCursor(11,2);
      lcd.write((uint8_t)6);
    }
  }

  if (charPosition == 10 and powerUp)
  {
    lcd.clear();
    for (int i = 2; i > 1; i++)
    {
      lcd.setCursor(6, 1);
      lcd.print("YOU WIN!");
      lcd.setCursor(5, 0);
      lcd.print("*");
      lcd.setCursor(5, 2);
      lcd.print("*");
      lcd.setCursor(14, 0);
      lcd.print("*");
      lcd.setCursor(14, 2);
      lcd.print("*");
    }
  }
}

void cenario()
{
  for (int i = 0; i < 10; i++)
  {
    static int contador1 = 0;
    static int contador2 = 1;
    lcd.setCursor(contador1, 0);
    lcd.write((uint8_t)2);
    lcd.setCursor(contador2, 0);
    lcd.write((uint8_t)3);

    contador1 += 2;
    contador2 += 2;
  }

  for (int i = 0; i < 20; i++)
  {
    lcd.setCursor(i, 3);
    lcd.write(255);
  }
}