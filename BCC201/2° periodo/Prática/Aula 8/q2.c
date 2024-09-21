#include <stdio.h>

#define TAM 15

int main() {
  //Declaração das variaveis
  int vet[TAM];
  int n, aux;

  printf("Entre com os 15 valores:");
  for(int i = 0; i < TAM; i++){
      scanf("%d", &vet[i]);
      }
  
  printf("\nEntre com o valor de n:");
  scanf("%d", &n);
        
  for(int i = 0; i < n; i++){
      aux = vet[0];
           
  for(int j = 0; j < TAM; j++){
      vet[j] = vet[j + 1];
      }
      vet[TAM - 1] = aux;
   }
        
  for(int j = 0; j < TAM; j++){
      printf("%d ", vet[j]);
      }
        
    printf("\n");

       return 0;
  
 }