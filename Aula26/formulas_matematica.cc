/*
Julia Iglesias
24/02/2025
Descricao: exercicio de matematica
*/

//************DECLARACAO DE VARIAVEIS GLOBAIS******************

int numeroA = 14;
int numeroB = 5;
int resultado = 0;
float resultadoReal = 0;

void setup()
{
  Serial.begin(9600);
  
//**SOMA**  
  resultado = numeroA + numeroB;
  Serial.print("A soma do numero A com o B eh: ");
  Serial.println(resultado);
  
//**SUBTRACAO**
  resultado = numeroA - numeroB;
  Serial.print("A subtracao do numero B pelo A eh: ");
  Serial.println(resultado);
  
//**MULTIPLICACAO**
  resultado = numeroA * numeroB;
  Serial.print("A multiplicacao do numero A pelo B eh: ");
  Serial.println(resultado);
  
//**DIVISAO**
  resultado = numeroA / numeroB;
  Serial.print("A divisao do numero A pelo B eh: ");
  Serial.print(resultado);
  resultado = numeroA%numeroB;
  Serial.print(" e sobra: ");
  Serial.println(resultado);
  resultadoReal = (float)numeroA / (float)numeroB;
  Serial.print("Ou ");
  Serial.print(resultadoReal, 1);//o numero depois da virgula limita a impressao do resultado em 1 casa decimal

//**POTENCIA**
  resultado = pow(numeroA, numeroB);
  Serial.print("numero A  elevado B eh: ");
  Serial.println(resultado);
  
//**RAIZ QUADRADO**
  resultadoReal = sqrt(numeroA);
  Serial.print("A raiz quadrada do numero A eh: ");
  Serial.println(resultadoReal);

//**MODULO**
  resultado = abs(numeroA * -1);
  Serial.print("O modulo do numero A eh: ");
  Serial.println(resultado);

//**RESTRICAO**
  resultado = constrain(numeroA, -3, 5);//restringe a variavel numero A aos limites -3 e 5.
  Serial.println(resultado);
  
//**MAPEAMENTO**
  resultado = map(numeroA, 0, 20, 0, 10);//map (valor, deMenor, deMaior, paraMenor, paraMaior)
  Serial.println(resultado);
 
//OPERADORES DE ATRIBUICAO
  Serial.println(numeroA += 5);//numeroA = numeroA + 5
  Serial.println(numeroA -= 5);//numeroA = numeroA - 5 
  Serial.println(numeroA *= 2);//numeroA *= 2;
  Serial.println(numeroA /= 2);//numeroA /= 2;
  
//INCREMENTAR A VARIAVEL
  //numeroA = numeroA + 1;
  Serial.println(numeroA++);//pos incremento (valor+1 porem aparece apenas antes de somar)
  Serial.println(++numeroA);//pre incremento (1+ valornovo e aparece somado)
  
//DECREMENTAL A VARIAVEL
  //numeroA = numeroA -1;
  Serial.println(numeroA--);//pos incremento (valor-1 porem aparece apenas antes de somar)
  Serial.println(--numeroA);//pre incremento (1- valornovo e aparece somado)
  
  resultadoReal = (2.0 / 5.0) + (2 * 3); //se quer um resultado flutuante com virgula tem que por .0 em algum
  Serial.println(resultadoReal);
  
//formula do map:  
resultado = (valor-deMenor) * (paraMaior-paraMenor) / (deMaior-deMenor) + paraMenor
}

void loop()
{
  
}