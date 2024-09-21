#include <stdio.h>
#include <stdlib.h>

int main (){
	//declaração das variáveis 
  int n, aux = 0;
  double soma, contador;
  int* vet;

  printf ("Digite o valor de n: ");
  scanf ("%d", &n);
  vet = (int*) malloc (sizeof(int) *n); //alocando vetor
  printf ("Digite os valores do vetor: ");

  for (int i = 0; i < n; i++){
     scanf ("%d", &vet[i]);
  }

  for (int i = 0; i < n; i++){ //calculando a média 
    soma = soma + vet[i];
    contador++;
  }
  printf ("A média é: %.2g\n", soma/contador);

  // colocando em ordem crescente (1,2,3,4,5...)
  for(int i = 0; i < n; i++ ){
    for(int j = i + 1; j < n; j++ ) // sempre 1 elemento à frente
    {
      // se o (i > (i+1)) então o i passa pra frente (ordem crescente)
      if ( vet[i] > vet[j] ){
         aux = vet[i];
         vet[i] = vet[j];
         vet[j] = aux;
      }
    }
  } // fim da ordenação

  printf ("Vetor com os valores abaixo da média: [");

  for (int i = 0; i < n; i++){
    if (vet[i] < soma/contador){
      printf (" %d ", vet[i]);
    }
  }
  printf("]\n");

  printf("Vetor com os valores iguais ou acima da média: [");
  for (int i = 0; i < n; i++){
    if (vet[i] >= soma/contador){
      printf (" %d ", vet[i]);
    }
  }
  printf("]\n");
  free (vet);

  return 0;
}
