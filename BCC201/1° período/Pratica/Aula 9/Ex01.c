/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <stdlib.h>

int main (){
  int n;
  double soma, contador;
  int* vet;

  printf ("Digite o valor de n: ");
  scanf ("%d", &n);
  vet = (int*) malloc (sizeof(int) *n);
  printf ("Digite os valores do vetor: ");

  for (int i = 0; i < n; i++){
     scanf ("%d", &vet[i]);
  }

  printf ("O vetor e [ ");

  for (int i = 0; i < n; i++){
    printf ("%d  ", vet[i]);
    soma = soma + vet[i];
    contador++; 
}
  printf ("]\n");
  printf ("A media e: %.lf\n", soma/contador);

  for (int i = 0; i < n; i++){
    if (vet[i] < soma/contador){
      printf ("Vetor com os valores abaixo da media: %d\n", vet[i]);
    }
  }
  
  for (int i = 0; i < n; i++){
    if (vet[i] >= soma/contador){
      printf ("Vetor com os valores iguais ou acima da media: %d\n", vet[i]);
    }
  }
  free (vet);

  return 0; 
}