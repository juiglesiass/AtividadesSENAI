// C++ code

// 5 Exercicios diversos
// data 27/02/2025

//(5)POSITIVO E NEGATIVO
int valor = 0;

//(6)AJUSTE DE SALARIO ABAIXO DE 1K + 10%
String nome = "Julia Iglesias";
String cargo = "Front-End Developer";
float salario = 999.99;
float salarioNovo = (salario * 0.1) + salario ;

//(7)AJUSTE DE SALARIO ABAIXO DE 500 + 30%
float salario2 = 500.01;
float salarioNovo2 = (salario2 * 0.3) + salario2 ;

//(8)QUAL O MAIOR NUMERO?
float numero1 = 4;
float numero2 = 5;

//(9)AVALIACAO DE NOTAS
float nota1 = 2;
float nota2 = 2;
float nota3 = 2;
float nota4 = 2;
float media = (nota1 + nota2 + nota3 + nota4) / 4;


void setup(){
  
  //(5)POSITIVO E NEGATIVO
  Serial.begin(9600);
  if(valor > 0){
  Serial.print("(1)O numero: ");
  Serial.print(valor);
  Serial.println(" eh positivo");
  }
  else if(valor < 0){
  Serial.print("(1)O numero: ");
  Serial.print(valor);
  Serial.print(" eh negativo");
  }
  else{
  Serial.print("(1)O numero: ");
  Serial.print(valor);
  Serial.println(" nao eh negativo nem positivo");
  }
  
  //(6)AJUSTE DE SALARIO ABAIXO DE 1K + 10%
  if (salario < 1000,00){
  salario = salarioNovo;
  Serial.println("(2)");
  Serial.println(nome);
  Serial.println(cargo);
  Serial.println(salarioNovo);
  }
  else {
  Serial.println("(2)");
  Serial.println(nome);
  Serial.println(cargo);
  Serial.println(salario);
  }
  
  //(7)AJUSTE DE SALARIO ABAIXO DE 500 + 30%
  if (salario2 < 500.00){
  salario2 = salarioNovo2;
  Serial.print("(3)Salario ajustado para: ");
  Serial.print(salarioNovo2);
  }
  else {
  Serial.println("(3)O funcionario nao tem direito ao aumento.");
  }
  
  //(8)QUAL O MAIOR NUMERO?
  if (numero1 > numero2){
  Serial.print("(4)O maior numero eh: ");
  Serial.print(numero1);
  }
  else {
  Serial.print("(4)O maior numero eh: ");
  Serial.println(numero2);
  }
  
  //(9)AVALIACAO DE NOTAS
  Serial.println("(5)");
  Serial.println(media); 
  if (media >= 7.0){
  Serial.println("APROVADO");
  }
  else if (media > 5.0 && media < 7.0){
  Serial.println("RECUPERACAO");
  }
  else {
  Serial.println("REPROVADO");
  }
}

void loop()
{
  
}