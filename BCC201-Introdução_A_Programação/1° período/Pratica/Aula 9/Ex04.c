/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdlib.h>
#include <stdio.h>

int main() {
  int i,j,n;
  printf("Digite as dimensoes da matriz: ");
  scanf("%d",&n);
  int matriz[n][n],somalin[n],somacol[n],somadiag1=0,somadiag2=0;
  printf ("       Digite os elementos: \n");
  for(i=0;i<n;i++) {
   somalin[i]=0;
    for(j=0;j<n;j++) {
      if(i==0)somacol[j]=0;
      printf ("Digite o %dº elemento da %dº Linha: ",j+1,i+1);
      scanf("%d",&matriz[i][j]);
      somalin[i] += matriz[i][j];/* somatorio das linhas */
      if(i==j)somadiag1 += matriz[i][j];/* somatorio da diagonal principal */
        }
      printf("\n");
    }
  for(i=0;i<n;i++)/* somatorio das colunas */
    for(j=0;j<n;j++)
      somacol[i] += matriz[j][i];

  for(i=0;i<n;i++) {
    for(j=0;j<n;j++)
      printf("%d ",matriz[i][j]);

      printf(" %d\n",somalin[i]);;
    }
    printf("\n");
  for(i=0;i<n;i++)
    printf("%d ",somacol[i]);

     printf("\n\n");
  j=n-1;
  somadiag2=0;
  /* somatorio diagonal secundária */
  for (i=0;i<n;i++) {
    somadiag2 += matriz[i][j];
    j--;
    }
  if (somadiag1 != somadiag2) {
    printf ("Nao e quadrado magico!\n\n");
    return 0;
  }
  for(i=0;i<n;i++) {
    if((somalin[i] != somalin[0])||(somacol[i] !=somalin[0])||(somadiag1!=somalin[i])||(somadiag2!=somalin[i])) {
      printf ("Nao e quadrado magico!\n");
        return 0;
        }
    }
    printf ("A matriz é um quadrado magico!\n\n");
    return 0;
}