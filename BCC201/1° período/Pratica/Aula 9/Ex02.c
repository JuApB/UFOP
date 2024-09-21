/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <stdlib.h>

double ** criaMatriz(int m, int n){
  double **mat;
  mat =(double**) malloc(m * sizeof(int*));
  for (int i = 0; i < m; i++) {
    mat[i] =(double*) malloc(m * sizeof(int));
            
  }
    return mat;
 }
 
 void leMatriz(double **A,int m,int n){  
   for(int i = 0;i < m; i++){ 
    for(int j = 0;j < n; j++){		
      printf("\nDigite o valor da linha [%d] coluna [%d]: ", i + 1,j + 1);
      scanf("%lf", &A[i][j]);
	    }
    }
 }
 
 void imprimeMatriz(double **A,int m, int n){
  printf("\n\n");
  for(int i = 0; i < m;i++){
   	for(int j = 0; j < n;j++){
     printf("\t|%.lf|", A[i][j]);		
	   }
   	printf("\n");
   } 
 }

 void imprimeTrans(double **At,int m,int n){
   printf("\n\n");
  for(int i = 0; i < n; i++){
   for(int j = 0; j < m; j++){
   	printf("\t|%.lf|", At[i][j]);
    }
   	printf("\n");
   } 
 }
 
void liberaMatriz(double **A, int m, int n){
  for (int i = 0; i < m; i++)
    free(A[i]);
    free(A);
 }

double ** transposta(double **A, int m, int n){
  double **At;
    At=(double**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
    At[i]=(double*) malloc(m * sizeof(int));
	}
	
	for(int i = 0; i < n; i++){
	  for(int j = 0; j < m; j++){
		At[i][j]=A[j][i];
	  }
	}	
	return At;	
  }

int main (){
  int m, n;
	double **A, **At;
     
  printf("\n Digite as dimensoes da matriz: ");
  scanf("%d%d", &m, &n);
     
  A=criaMatriz(m, n);
	leMatriz(A, m, n);
	At=transposta( A, m, n);
	      
	printf("\n\n Matriz original: \n");
	      
	imprimeMatriz(A, m, n);
	printf("\n\n Matriz transposta: \n");
	
	imprimeTrans(At, m, n);
	
	liberaMatriz(A, m, n);
	liberaMatriz(At, m, n);
	
	return 0;
}
