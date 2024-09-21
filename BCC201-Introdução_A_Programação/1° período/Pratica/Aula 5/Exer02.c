/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

int verificaCpf(long int cpf);

int main() {
  long int cpf;
  printf("CPF: ");
  scanf("%ld", &cpf);
  int retorno = verificaCpf(cpf);
  if (retorno == 1)
    printf("CPF válido.");
  else
    printf("CPF inválido.");
  return 0;
}

int verificaCpf(long int cpf) {
  int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11;
  long int divisor = 10000000000;

/* 
   Variável m e z é da validaçao do primeiro dígito
   Variável n e y é da validaçao do segundoo dígito
*/
  int m, z, n, y;
  for (int i = 0; i < 1; i++) {
    x1 = cpf / divisor;
    divisor /= 10;
    x2 = (cpf / divisor) % 10;
    divisor /= 10;
    x3 = (cpf / divisor) % 10;
    divisor /= 10;
    x4 = (cpf / divisor) % 10;
    divisor /= 10;
    x5 = (cpf / divisor) % 10;
    divisor /= 10;
    x6 = (cpf / divisor) % 10;
    divisor /= 10;
    x7 = (cpf / divisor) % 10;
    divisor /= 10;
    x8 = (cpf / divisor) % 10;
    divisor /= 10;
    x9 = (cpf / divisor) % 10;
    divisor /= 10;
    x10 = (cpf / divisor) % 10;
    divisor /= 10;
    x11 = (cpf / divisor) % 10;
    m = x1 * 10 + x2 * 9 + x3 * 8 + x4 * 7 + x5 * 6 + x6 * 5 + x7 * 4 + x8 * 3 + x9 * 2;
    z = (m * 10) % 11;
    if (z == 10)
      z = 0;
    if (z == x10) {
      n = x1 * 11 + x2 * 10 + x3 * 9 + x4 * 8 + x5 * 7 + x6 * 6 + x7 * 5 + x8 * 4 + x9 * 3 + x10 * 2;
      y = (n * 10) % 11;
    }
  }
  if (z == x10 && y == x11)
    return 1;
  else
    return 0;
}