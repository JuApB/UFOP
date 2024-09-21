#include <stdio.h>
#include <stdlib.h>

//Implementando a funçao para trocar os caracteres
char substituir_letras(char letra){
   char caracter_novo;

   switch (letra) {
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

int main() {
    //declaraçao de variaveis
  char texto[70];
  int i;

  printf("Digite o texto para censurar: ");
  fgets(texto, 70, stdin);

  i = 0;
  //chamando a funçao dentro de um comando de repetiçao
  while(texto[i] != '\0')
    {
      texto[i] = substituir_letras(texto[i]); 
      i++;
    }

  printf("\n%s", texto);
  
  return 0;

  }

  
