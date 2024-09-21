/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <stdlib.h>
  
int main(){
  int linA, colA, linB, colB;
  
  printf("PRODUTO DE MATRIZES A X B. \n \n");
  printf("Quantidade de linhas de A = ");
  scanf("%d", &linA);
  printf("Quantidade de colunas de A = ");
  scanf("%d", &colA);
  printf("Quantidade de linhas de B = ");
  scanf("%d", &linB);
  printf("Quantidade de colunas de B = ");
  scanf("%d", &colB);
  
  float A[linA][colA];
  float B[linB][colB];
  float C[linA][colB];
  float temp;

  if(colA != linB)
  {
    printf("A multiplicação não pode ser realizada. \n");
    printf("A quantidade de colunas de A é diferente deo número de linhas de B. \n");
    return 0;
  }

   //Carregamento da Matriz A

  printf(" \n Carregamento da Matriz A \n \n");
  for(int i=0; i<=linA; i++)
    {
      for(int j=0; j<=colA; j++)
        {
          printf("A[%d][%d]=", i+1, j+1);
          scanf("%f", &A[i][j]);
        }
    }

   //Carregamento da Matriz B

  printf(" \n Carregamento da Matriz B \n \n");
  for(int i=0; i<=linB; i++)
    {
      for(int j=0; j<=colB; j++)
        {
          printf("B[%d][%d]=", i+1, j+1);
          scanf("%f", &B[i][j]);
        }
    }

  printf(" \n Matriz A \n \n");
  
  for(int i=0; i<linA; i++){
    for(int j=0; j<colA; j++){
      if(j != (colA-1)){
        printf("%.2f \t", A[i][j]);
      }
      else{
        printf("%.2f \n", A[i][j]);
        }
    }
  }
 
  printf("\n \n");

  printf(" \n Matriz B \n \n");
  
  for(int i=0; i<linB; i++){
    for(int j=0; j<colB; j++){
      if(j != (colB-1)){
        printf("%.2f \t", B[i][j]);
      }
      else{
        printf("%.2f \n", B[i][j]);
        }
    }
  }

  for(int k1=0; k1<linA; k1++){
    for(int k2=0; k2<colB; k2++){
      temp=0.0;
      for(int i=0; i<colA; i++){
        temp=temp+A[k1][i]*B[i][k2];
      }
      C[k1][k2]=temp;
    }
  }
  printf("\n \n");
 
  printf("\n MATRIZ C = A X B \n");
    for(int i=0; i<linA; i++){
      for(int j=0; j<colB; j++){
        if(j!=(colB-1))
          printf("%.2f \t", C[i][j]);
        else
          printf("%.2f \n", C[i][j]);
        }
      }
  
    return 0;
} 
