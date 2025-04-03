// C++ code
//

//---------------TABUADA NO SERIAL-----------------

int resultado = 0;
int multiplicador = 5;

//------VERIFICA SE N ESTA DENTRO DE UM ARRAY-------

int array[5] = {1,2,3,4,5};
int numero = 53;
int encontrado = 0;

//----ACENDER 3 LEDS 1 POR 1, 3S CADA, APAGAR 1 POR 1-----
  
int pinLedsA[3] = {13,10,7};

// ACENDER E APAGAR 3 LEDS, PROGRESSIVAMENTE APENAS C/ BOTAO ON

int pinLedsB[3] = {4,3,2};


void setup()
{
  
  
//---------------TABUADA NO SERIAL-----------------
  
  Serial.begin(9600);
  Serial.println("TABUADA NO SERIAL");
  for(int i=0 ; i<=10 ; i++){
  resultado = i*multiplicador; 
  Serial.print(i);
  Serial.print(" x "); 
  Serial.print(multiplicador);
  Serial.print(" = "); 
  Serial.println(resultado);
  }
  
  
//------VERIFICA SE N ESTA DENTRO DE UM ARRAY-------
  
Serial.println("VERIFICA SE N ESTA DENTRO DE UM ARRAY");
  
  for(int i=0 ; i<=4 ; i++){ 
    
    if (numero == array[i]){
       encontrado = 1;
       Serial.print("Numero ");
       Serial.print(numero);
       Serial.print(" encontrado");
    }
    else if (i == 4 and encontrado==0){
       Serial.print("Numero ");
       Serial.print(numero);
       Serial.print(" nao encontrado");
    }
  }
  
  
//----ACENDER 3 LEDS 1 POR 1, 3S CADA, APAGAR 1 POR 1-----

Serial.println("ACENDER 3 LEDS 1 POR 1, 3S CADA, APAGAR 1 POR 1");
  
   for(int i=0 ; i<=2 ; i++){
   pinMode(pinLedsA[i], OUTPUT);
   }  
  
   for(int i=0 ; i<=2 ; i++){
   digitalWrite(pinLedsA[i], HIGH);
   delay(500);
   }
  
   delay(3000);
  
   for(int i=0 ; i<=2 ; i++){
   digitalWrite(pinLedsA[i], LOW);
   delay(500);
   }

  
// ACENDER E APAGAR 3 LEDS PROGRESSIVAMENTE APENAS C/ BOTAO ON

  pinMode(5, INPUT_PULLUP);
  
}

void loop()
{
  
// ACENDER E APAGAR 3 LEDS PROGRESSIVAMENTE APENAS C/ BOTAO ON
  
  bool estadoBotao = digitalRead(5);
  
     for(int j=0 ; j<=2 ; j++){
     pinMode(pinLedsB[j], OUTPUT);
     }
  
    while (estadoBotao == 0){

     for(int j=0 ; j<=2 ; j++){
     digitalWrite(pinLedsB[j], HIGH);
     delay(500);
     }

     for(int j=0 ; j<=2 ; j++){
     digitalWrite(pinLedsB[j], LOW);
     delay(500);
     
	 estadoBotao = digitalRead(5);
     }
  }
  
     for(int j=0 ; j<=2 ; j++)
     digitalWrite(pinLedsB[j], LOW);
	
}
