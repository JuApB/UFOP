/*
    Nome: Juliana Aparecida Borges 
    Matrícula: 21.2.4156
    Turma: 31
     */
#include <stdio.h>


int main()
{
   int ano; 
   printf("Digite aqui um ano\n");
   scanf("%d", &ano);
   
   if (ano % 4 == 0 && ano % 100 != 0) {
      printf("\n%d é bissexto\n", ano); 
   }
   else if (ano % 100 == 0 && ano % 400 == 0) {
      printf("%d é bissexto\n", ano);
   }
   else {
     printf("%d não é bissexto\n", ano);
   }
  return(0);
}
  
