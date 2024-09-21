/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

int main() {
  // declaraçao das variáveis   
  float c, f, k;
  // atribuição de valores
  c = 28;
  // cálculo de Celsius para Fahrenheit
  f = (c * 9 / 5 + 32);
  // cálculo de Celsius para Kevin
  k = (c + 273.15);
  printf("c = %.f\n",c); 
  printf("f = %.2f ",f);
  printf("k = %.2f ",k);
    return 0;

}