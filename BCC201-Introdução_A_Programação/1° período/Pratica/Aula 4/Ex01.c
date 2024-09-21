/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */

#include <stdio.h>

long long fat(int n);

int main() {
  long long n;
  long long fat = 1;
printf("Digite um numero: ");
scanf("%lld", &n);

  long long i = n;
  while(i >= 1) {
    fat *= i;
    i--;
}
 printf("O fatorial de %lld é: %lld", n, fat);
  
  return 0;
}
 