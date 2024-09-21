#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tam 51

int main() {
  //declaraçao das variaveis
  char palavra[tam], inversa[tam];
  int aux;
  
  //comando de repetiçao para verificar se a palavra é palindromo
  while(strcmp (palavra,"FIM") != 0){
    printf("Digite uma palavra ou FIM para sair: ");
    fflush(stdin);
    fgets(palavra, 51, stdin);
    palavra[strlen(palavra)-1] = '\0';
    
    if(strcmp (palavra,"FIM") == 0)
      break;
      
    aux = strlen(palavra);
  
    for(int i = 0; i < strlen(palavra); i++){
     inversa[i] = palavra[aux - (i+1)];
    } 
    inversa[strlen(palavra)] = '\0';
    
    if(strcmp(palavra, inversa) == 0){
      printf("\n%s é um palindromo\n\n", palavra);
     }
    else
      printf("\n%s não é um palindromo\n\n", palavra);
  }

  return 0;
}
