#include <stdio.h>

//Prototipo da função 
int primo(int n);

int main(){
	//Declaração das variáveis 
	int d = 2;
	int primo = 1;
	int n;
	printf("Digite um número: ");
	scanf("%d", &n);

    if (n <= 1)
    primo = 0;

//comando while para verificar se o número é primo
    while (primo == 1 && d <= n / 2) { 
  	 if (n % d == 0)
       primo = 0;
     d = d + 1;
  }
  
    if (primo == 1)
      printf("\n%d é um número primo! \n", n);
    else
      printf("\n%d não é um número primo! \n", n);

  return 0;
}