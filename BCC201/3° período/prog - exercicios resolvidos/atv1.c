//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>

int main(){
    int x, y, z; //Declaração das Variaveis
    printf("Entre com os números:\n\n");
    scanf("%d%d%d", &x, &y, &z);
  
    //If, else if para verificar qual é menor, intermediario e maior
    if (x < y && y < z) {
       printf("\nMenor: %d\n", x);
       printf("\nIntermediário: %d\n", y);
       printf("\nMaior: %d\n", z);
     }
    else if (x < z && z < y) {
       printf("\nMenor: %d\n", x);
       printf("\nIntermediário: %d\n", z);
       printf("\nMaior: %d\n", y);
     }
    else if (y < x && x < z) {
       printf("\nMenor: %d\n", y);
       printf("\nIntermediário: %d\n", x);
       printf("\nMaior: %d\n", z);
     }
    else if (y < z && z < x) {
       printf("\nMenor: %d\n", y);
       printf("\nIntermediário: %d\n", z);
       printf("\nMaior: %d\n", x);
     }
    else if (z < x && x < y) {
       printf("\nMenor: %d\n", z);
       printf("\nIntermediário: %d\n", x);
       printf("\nMaior: %d\n", y);
     }
    else if (z < y && y < x) {
       printf("\nMenor: %d\n", z);
       printf("\nIntermediário: %d\n", y);
       printf("\nMaior: %d\n", x);
     }
  
    return 0;

  }
