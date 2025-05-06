#include <Arduino.h>

struct Pessoa
{
  char nome [20];
  int idade;
  float altura;
  bool calvice;
};

struct cor
{
  char nome [20];
  char R;
  char G;
  char B;
};

Pessoa aluno;
Pessoa professor;
cor verdeAgua;
cor verdeMusgo;
cor verdeBlusa;

void setup()
{
  Serial.begin(9600);

  /*
  strcpy(aluno.nome, "Julia");
  aluno.idade = 21;
  aluno.altura = 1.71;
  aluno.calvice = false;

  strcpy(professor.nome, "Rafaella");
  professor.idade = 12;
  professor.altura = 0.70;
  professor.calvice = true ;

  Serial.printf("meu nome eh: %s \n \r", aluno.nome);
  Serial.printf(" e tenho %d anos \n \r", aluno.idade);
  Serial.printf("tenho %.2f metros de altura \n \r", aluno.altura);
  aluno.calvice ? Serial.println ("calvo") : Serial.println ("nao calvo");

  Serial.printf("meu nome eh: %s \n \r", professor.nome);
  Serial.printf(" e tenho %d anos \n \r", professor.idade);
  Serial.printf("tenho %.2f metros de altura \n \r", professor.altura);
  Serial.printf("e %s calvo", professor.calvice ? "sou": "nao sou");
*/

  strcpy(verdeAgua.nome, "verde-agua");
  verdeAgua.R = 60;
  verdeAgua.G = 179;
  verdeAgua.B = 150;

  //rgba(60, 179, 150)

  strcpy(verdeMusgo.nome, "verde-musgo");
  verdeMusgo.R = 34;
  verdeMusgo.G = 58;
  verdeMusgo.B = 35;

  strcpy(verdeBlusa.nome, "verde-blusa");
  verdeBlusa.R = 29;
  verdeBlusa.G = 60;
  verdeBlusa.B = 57;

  Serial.printf("o nome da cor eh: %s \n \r", verdeAgua.nome);
  Serial.printf("Ela tem %d de vermelho \n \r", verdeAgua.R);
  Serial.printf("%d de verde \n \r", verdeAgua.G);
  Serial.printf("e %d de azul \n \r", verdeAgua.B);

  Serial.printf("o nome da cor eh: %s \n \r", verdeMusgo.nome);
  Serial.printf("Ela tem %d de vermelho \n \r", verdeMusgo.R);
  Serial.printf("%d de verde \n \r", verdeMusgo.G);
  Serial.printf("e %d de azul \n \r", verdeMusgo.B);

  Serial.printf("o nome da cor eh: %s \n \r", verdeBlusa.nome);
  Serial.printf("Ela tem %d de vermelho \n \r", verdeBlusa.R);
  Serial.printf("%d de verde \n \r", verdeBlusa.G);
  Serial.printf("e %d de azul \n \r", verdeBlusa.B);

}

void loop()
{

}