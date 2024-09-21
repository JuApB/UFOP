#include <stdio.h>
#include <stdlib.h>

int main() {
  //declaraçao das variaveis    
  int i, j, n;
  printf("Digite o valor de n: "); //valor da dimensao da matriz
  scanf("%d",&n);

  int matriz[n][n], somaL[n], somaC[n], somaDiag1 = 0, somaDiag2 = 0;
  printf ("Digite os valores da matriz n x n: \n"); //pedindo os valores da matriz

  for(i = 0; i < n; i++) {
    somaL[i]=0;
     for(j = 0; j < n; j++) {
       if(i==0)somaC[j]=0;
        scanf("%d",&matriz[i][j]);
        somaL[i] += matriz[i][j];// somatorio das linhas
      if(i==j)somaDiag1 += matriz[i][j];// somatorio da diagonal principal 
        }
    }

  for(i = 0; i < n; i++)// somatorio das colunas
    for(j = 0; j < n; j++)
      somaC[i] += matriz[j][i];

     printf("\n");
 
  j = n-1;
  somaDiag2=0;

  // somatorio diagonal secundária 
  for (i = 0; i < n; i++) {
    somaDiag2 += matriz[i][j];
    j--;
    }
    
  if (somaDiag1 != somaDiag2) { //verificando se é quadrado magico ou não
    printf ("Esta matriz NÃO é um quadrado mágico!\n\n");
    return 0;
  }
  
  for(i = 0; i < n; i++) {
    if((somaL[i] != somaL[0]) || (somaC[i] != somaL[0]) || (somaDiag1 != somaL[i]) || (somaDiag2 != somaL[i])) {
      printf ("Esta matriz NÃO é um quadrado mágico!\n"); //imprimindo que nao é  um quadrado magico
        return 0;
        }
    }
   
    printf ("Esta matriz é um quadrado mágico!\n\n"); //imprimindo que e um quadrado magico
    
    return 0;
}