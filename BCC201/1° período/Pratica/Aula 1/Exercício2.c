/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

int main() {
  // declaraçao das variáveis   
  float x1, x2, x3, y;
  // atribuição de valores
  x1 = 5;
  x2 = 5;
  x3 = 5;
  // cálculo de y
  y = ((x1 + x2 * x2 + x3 * x3) * (x1 + x2 * x2 + x3 * x3) - (x1 * x2 * x3) * (x1 * x2 * x3));
  printf("x1 = %.f, x2 = %.f, x3 = %.f\n",x1,x2,x3); 
  printf("y = %.f ",y);
    return 0;

}