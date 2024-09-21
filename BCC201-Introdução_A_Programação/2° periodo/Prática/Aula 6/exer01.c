#include <stdio.h>

//Protótipo da função 
long long fat(int n);

int main(){
	//Declaração das Variáveis 
  long long n;
  long long fat = 1;
  
  printf("Digite o valor de n: ");
  scanf("%lld", &n);

  long long i = n; 
  
  //comando while para fatorar
  while (i >= 1) {
  	fat *= i;
  	i--;
  }
 
  //impressão do resultado da fatoração 
  printf("\n%lld! = %lld\n", n, fat);
  
  return 0;
}
