// C++ code
//


int pinLeds[5] = {13,10,8,5,2};


void setup()
{
  for(int i=0 ; i<=5 ; i++){
  pinMode(pinLeds[i], OUTPUT);
  }
}

void loop()
{
  for(int i=0 ; i<=5 ; i++){
      digitalWrite(pinLeds[i], HIGH);
      
  }
  delay(500);
  
  for(int i=0 ; i<=5 ; i++){
      digitalWrite(pinLeds[i], LOW);
      
  }
  delay(500);
}