/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

int main() {
    // declaraçao das variáveis   
  float a, b, c, d, x;
  // atribuição de valores
  a = 10;
  b = 10;
  c = 10;
  d = 10;
  // cálculo de x
  x = a * a * a * ((b + c) / d);
  printf("a = %.f, b = %.f, c = %.f, d = %.f\n",a,b,c,d); 
  printf("x = %.f ",x);
    return 0;
}