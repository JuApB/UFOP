/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */

#include <stdio.h>
#include <stdlib.h>

char substituir_letras(char letra);

int main() {
  char texto[70];
  int i;

  printf("Digite o texto para censurar: \n");
  fgets(texto, 70, stdin);

  i = 0;
  while(texto[i] != '\0')
    {
      texto[i] = substituir_letras(texto[i]); 
      i++;
    }

  printf("O texto com as letras substituídas é:\n%s", texto);

  }

  char substituir_letras(char letra)
{
  char caracter_novo;

  switch (letra)
    {
      case 'a':
        caracter_novo = '@';
        break;
      case 'e':
        caracter_novo = '_';
        break;
      case 'i':
        caracter_novo  = '|';
        break;
      case 'o':
        caracter_novo = '0';
        break;
      case 'u':
        caracter_novo = '#';
        break;
      case 's':
        caracter_novo = '$';
        break;

      default:
        caracter_novo = letra;
        break;
    }
  return caracter_novo;
  
}