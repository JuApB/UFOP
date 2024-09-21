#include <stdio.h>

int main(){
  int a, b, c; //Declaração das Variaveis
  printf("Entre com os números:\n");
  scanf("%d%d%d", &a, &b, &c);
  
  //If, else if para verificar qual é menor, intermediario e maior
  if (a < b && b < c) {
   printf("Menor: %d\n", a);
   printf("Intermediário: %d\n", b);
   printf("Maior: %d\n", c);
  }
  else if (a < c && c < b) {
   printf("Menor: %d\n", a);
   printf("Intermediário: %d\n", c);
   printf("Maior: %d\n", b);
  }
  else if (b < a && a < c) {
   printf("Menor: %d\n", b);
   printf("Intermediário: %d\n", a);
   printf("Maior: %d\n", c);
  }
  else if (b < c && c < a) {
   printf("Menor: %d\n", b);
   printf("Intermediário: %d\n", c);
   printf("Maior: %d\n", a);
  }
  else if (c < a && a < b) {
   printf("Menor: %d\n", c);
   printf("Intermediário: %d\n", a);
   printf("Maior: %d\n", b);
  }
  else if (c < b && b < a) {
   printf("Menor: %d\n", c);
   printf("Intermediário: %d\n", b);
   printf("Maior: %d\n", a);
  }
  
  return 0;
  }
