#include <stdio.h>

int main(){
  //Declaração de Variavéis
  float c, f, k;
  //Entrada de Dados
  printf("Entre com o valor em graus Celsius: ");
  scanf("%f", &c);
  //Cálculo
  f = (c * 9 / 5 + 32);
  k = (c + 273.15);
  //Saída de dados
  printf("Celsius: c = %.2f\n", c);
  printf("Fahrenheit: f = %.2f\n", f);
  printf("Kelvin: k = %.2f\n", k);
  return 0;
  }
