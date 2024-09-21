#include <stdio.h>

int main(){
  //Declaração de Variavéis
  float x1, x2, x3, y;
  //Entrada de Dados
  printf("Entre com os valores de x1, x2 e x3: ");
  scanf("%f%f%f", &x1, &x2, &x3);
  //Cálculo
  y = (x1 + (x2 * x2) + (x3 * x3)) * (x1 + (x2 * x2) + (x3 * x3)) - (x1 * x2 * x3) * (x1 * x2 * x3);
  //Saída de dados
  printf("y = %.2f", y);
  return 0;
  }
