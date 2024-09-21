#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tam 70

int main() {

  char nome[tam], sobrenome[tam];
  int x, y, aux = 0;

  printf("Digite um nome completo:");
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
  
  x = x - 3;
  y = strlen(sobrenome);
  nome[aux] = '\0';

  printf("\n%s, %s\n\nTotal de letras: %d\n\nTotal de letras do último sobrenome: %d\n",sobrenome, nome, x, y);

  return 0;
}