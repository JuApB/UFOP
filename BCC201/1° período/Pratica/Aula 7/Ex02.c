/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tam 51

int main(void) {

  char palavra[tam], inversa[tam];
  int aux;
  
  do{
    printf("\nDigite uma palavra ou FIM para sair: ");
    fflush(stdin);
    fgets(palavra, 51, stdin);
      palavra[strlen(palavra)-1] = '\0';
    
    aux = strlen(palavra);
  
   for(int i = 0; i < strlen(palavra); i++){
     inversa[i] = palavra[aux - (i+1)];
     
   } 
    inversa[strlen(palavra)] = '\0';
    printf("Palavra: %s\nInversa: %s\n", palavra, inversa);
    
    if(strcmp(palavra, inversa) == 0){
      printf("%s é palindromo.", palavra);
    }
    else
      printf("%s não é palindromo.", palavra);


    
  }while(strcmp (palavra,"FIM") != 0);


  printf("\nSaindo!");


  return 0;
}