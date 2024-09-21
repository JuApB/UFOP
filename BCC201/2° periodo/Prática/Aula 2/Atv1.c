#include <stdio.h>

int main(){
  //Declaração de Variavéis
  int a, b, c, d, x;
  //Entrada de Dados
  printf("Entre com os valores de a, b, c, d: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);
  //Cálculo
  x = (a * a * a) * ((b + c) / d);
  //Saída de dados
  printf("x = %d", x);
  return 0;
  }
