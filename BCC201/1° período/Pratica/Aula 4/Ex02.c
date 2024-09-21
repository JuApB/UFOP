/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */

#include <stdio.h>

int ehPrimo(int n);

int main() {
  int d = 2;
  int ehPrimo = 1;
  int n;
printf("Digite um número: ");
scanf("%d", &n);

if (n <= 1)
	ehPrimo = 0;
  
while (ehPrimo == 1 && d <= n / 2) {
	if (n % d  == 0)
	    ehPrimo = 0;
	d = d + 1;
  }
  
if (ehPrimo == 1)
	printf("%d é um número primo! \n", n);
else 
	printf("%d não é um número primo! \n", n);
    return 0;
}
