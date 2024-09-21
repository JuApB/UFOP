/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */

#include <stdio.h>

int main(){
  //Declaração das Variáveis
    int troca, cont = 0;
    int vetor[15];

  //Pedindo para o usuário informar os valores do vetor
  while(cont < 15) {
        printf("Informe o valor numero %d: \n", cont + 1);
        scanf("%d", &vetor[cont]);
        cont++;
    }

    printf("Quantas posições quer rotacionar? ");
    scanf("%d", &troca);

  //Imprimindo os valores do vetor escolhido pelo usuário
    printf("Vetor informado: \n");
    for(int i = 0; i < 15; i++){
        printf("%d ",vetor[i]);
    }

  //Comando FOR para rotacionar o vetor
    int aux[troca];
      for (int i = 0; i < troca; i++){
        aux[i] = vetor[i];
    }

      for(int i = 0; i < 15 - troca; i++){
        vetor[i] = vetor[i + troca];
    }

       for (int i = 0; i < troca; i++){
        vetor [15 - troca + i] = aux[i];
    }

   //Impressão do vetor rotacionado para esquerda
        printf("\nVetor rotacionado: \n");
    for(int i = 0; i < 15; i++){
        printf("%d ",vetor[i]);
    }
  return 0;
}