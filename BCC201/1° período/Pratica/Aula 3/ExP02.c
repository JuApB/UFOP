/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

double calculaRaizes(float *a, float *b, float *c);

int main() {
  float a, b, c;
  printf("Digite os valores de a, b e c:\n");
  scanf("%f %f %f", &a, &b, &c);

  double retorno = calculaRaizes(&a, &b, &c);

  printf("Retorno: %.lf\n", retorno);
}

 double calculaRaizes(float *a, float *b, float *c) {
  float delta = *b * *b - 4 * *a * *c;
  if (delta >= 0)
    return 1;
  else return 0;
}