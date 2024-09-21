/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30

int main() {
   //Declaração das Variavéis
    int vet[TAM], i, abaixoMedia = 0, acimaMedia = 0, soma = 0;
    float media;

   //Semente
    srand(time(NULL));
  
    //Gerando valores aleatórios para o vetor
    for (i = 0; i < TAM; i++) {
        vet[i] = rand()%51;
    }

    //Calculando a media
    for (i = 0; i < TAM; i++) {
        soma = soma + vet[i];
    }
    media = soma / (float)TAM;

    // Cálculo - abaixo da média
    for(i = 0; i < TAM; i++){
      if (vet[i] < media){
        abaixoMedia++;
      }
    }
  
    //Cálculo - acima da media
    for (i = 0; i < TAM; i++) {
        if (vet[i] > media) {
            acimaMedia++;
        }
    }

    //Impressão das temperaturas
    printf("Temperaturas: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }

    //Impressão dos valores da media, abaixo da media e acima da media
    printf("\nMedia: %f", media);
    printf("\nAbaixo da media: %d", abaixoMedia);
    printf("\nAcima da media: %d", acimaMedia);

    return 0;
}
