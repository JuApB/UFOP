/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Criando a função
void imprimaQuantidade( int a[], int n){
	for(int i=1; i<=n; i++){
		
		printf("%d = %d\n", i, a[i]);	
	}
}

int main(){
  //Declaração daas Variavéis
	int n, num[100000];

  //Semente
	srand(time(NULL));

  //Comando do-while para o valor de N
	do{
		printf("Entre com um número inteiro <= 500:");
		scanf("%d",&n);
	}while(n>500);
	
	int a[n+1];
	for(int i=0;i<=n;i++)
		a[i] = 0;
	
	for(int i=0;i<100000; i++){
	
		num[i] = (srand(5)%n)+1;
		a[num[i]]++;
	}
	
	imprimaQuantidade(a,n);
	
	return 0;
}


