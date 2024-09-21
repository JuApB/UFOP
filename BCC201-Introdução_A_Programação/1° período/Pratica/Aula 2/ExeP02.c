/*
    Nome: Juliana Aparecida Borges 
    Matrícula: 21.2.4156
    Turma: 31
     */

#include <stdio.h>


int main()
{
   int a, b, c; 
   
   printf("Digite tres valores: ");
   scanf("%d%d%d", &a, &b, &c);
   
  
  if(a > b && b > c) {
     printf("Maior: %d\n", a);
     printf("Intermediario: %d\n", b);
     printf("Menor: %d\n", c);
        }
  else if(a > c && c > b) {
     printf("Maior: %d\n", a);
     printf("Intermediario: %d\n", c);
     printf("Menor: %d\n", b);
    }
  else if(b > c && c > a) {
     printf("Maior: %d\n", b);
     printf("Intermediario: %d\n", c);
     printf("Menor: %d\n", a);
        }
  else if(b > a && a > c) {
     printf("Maior: %d\n", b);
     printf("Intermediario: %d\n", a);
     printf("Menor: %d\n", c);
    }
  else if(c > b && b > a) {
     printf("Maior: %d\n", c);
     printf("Intermediario: %d\n", b);
     printf("Menor: %d\n", a);
        }
  else if(c > a && a > b) {
     printf("Maior: %d\n", c);
     printf("Intermediario: %d\n", a);
     printf("Menor: %d\n", b);
    }
return 0;
}