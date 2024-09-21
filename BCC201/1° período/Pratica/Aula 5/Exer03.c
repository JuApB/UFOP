/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

int main() {
//Declaração das Variáveis
  int linha, coluna;
   printf("Movimentos de um Bispo no xadrez!\n");
   printf("Digite a linha em que o Bispo se encontra: ");
   scanf("%d", &linha);
   printf("Digite a coluna em que o Bispo se encontra: ");
   scanf("%d", &coluna);

//Impressão do cabeçalho
  printf("\nMovimentos possíveis:\n\n");
  printf("      1  2  3  4  5  6  7  8 \n");
  printf("    ------------------------\n");

//Impressão da tabela
  for (int i = 1; i <= 8; i++) {
    printf(" %d | ", i);
    for (int j = 1; j <= 8; j++) {
      if (i == linha && j == coluna)
        printf(" o ");
      else if (i - j == linha - coluna || i + j == linha + coluna)
        printf(" x ");
      else 
        printf(" - ");
    }
   printf("\n");
  }
 return 0;
 }