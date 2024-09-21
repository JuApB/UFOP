/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <stdlib.h>

int main(){
  //Declarção das Variavéis
 int i, situacoes[15];
 float notasp1[15], notasp2[15], medias[15];

  /* 
    Não consegui fazer com que mostrasse o número do aluno para 
    identificá-lo, então coloquei esse printf que está abaixo para 
    ajudar o usuário a entender o preenchimento.
  */
   printf("Abaixo, digite todas as notas dos 15 alunos em sequência!");
  
  //Comando de repetição FOR
  for (i=0; i<15; i++) {
   printf("\nDigite a primeira e segunda nota do aluno(Lembrando que o valor total é 100): \n");
   scanf("%f%f", &notasp1[i], &notasp2[i]);
   medias[i] = (notasp1[i] + notasp2[i]) / 2;
    if (medias[i] >= 60) {
    situacoes[i] = 1;
   }
    else {
    situacoes[i] = 2;
   }
 }
  
 //Impressão da aprovação ou reprovação dos alunos
 for (i=0; i<15; i++) {
  if (situacoes[i] == 1)
   printf("\nAprovado!!!");
  else
   printf("\nReprovado!");
  }
   return 0;
}