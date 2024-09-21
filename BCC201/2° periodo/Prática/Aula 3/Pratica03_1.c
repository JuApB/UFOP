#include <stdio.h>

int main(){
  int ano; //Declaração da Variavel
  printf("Entre com o ano:\n");
  scanf("%d", &ano);
  
  //Comandos em if para saber se o ano é bissexto
  if (ano % 4 == 0 && ano % 100 != 0) {
   printf("O ano %d é bissexto\n", ano);
  }
  else if (ano % 100 == 0 && ano % 400 == 0) {
   printf("O ano %d é bissexto\n", ano);
  }
  else {
   printf("O ano %d não é bissexto\n", ano); 
  }
  
  return 0;
  }
