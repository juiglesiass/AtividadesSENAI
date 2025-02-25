// C++ code
//calculadora IMC

float peso=100; //em kg
float altura=1.80; //em m
float IMC=0;

void setup()
{
  Serial.begin(9600);
    
  IMC = peso / sq(altura);
  
  
  if(IMC <= 18.5) {
     Serial.println("magreza");
  }
     
  else if(IMC <= 24.9 & IMC > 18.5){
     Serial.println("normal");
  }
 
  else if(IMC <= 29.9 & IMC >= 25) {
     Serial.println("sobrepeso"); 
  }
     
  else if(IMC <= 34.9 & IMC >= 30) {
     Serial.println("obesidade");
  }
     
  else{
     Serial.println("obesidade grave");
  }
     
}

void loop(){
}