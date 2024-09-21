#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tam 70

int main() {

  char nome[tam], sobrenome[tam];
  int x, y, aux = 0;

  printf("\nDigite um nome completo: ");
  fflush(stdin);
  fgets(nome, tam, stdin);

  x = strlen(nome);
  nome[x-1] = '\0';

  for(int i =0; i< x; i++){
    if(nome[i] == ' ' ){
      aux = i;
      //break;
      }
  }
  for(int i =0; i< x; i++){
    sobrenome[i] = nome[aux+i];
  }

  for(int x = 0; sobrenome[x] != '\0'; x++) {
    while(sobrenome[x] == ' ') {
      for(int y = x; sobrenome[y] != '\0'; y++) {
        sobrenome[y] = sobrenome[y + 1];
            }
      }
    }

  y = strlen(sobrenome)-1;
  nome[aux] = '\0';

  printf("%s, %s\nTotal de letras: %d\nTotal de letras do ultimo sobrenome: %d",sobrenome, nome, x, y);

  return 0;
}