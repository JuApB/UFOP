#include <stdio.h>
#include <stdlib.h>

//prototipos e implementaçao das funçoes
double ** criaMatriz(int m, int n){
  double **mat;
  mat =(double**) malloc(m * sizeof(int*));
  for (int i = 0; i < m; i++) {
    mat[i] =(double*) malloc(n * sizeof(int*));
            
  }
    return mat;
 }
 
 void leMatriz(double **A,int m,int n){  
   printf("Digite a matriz:\n");
   for(int i = 0; i < m; i++){ 
    for(int j = 0; j < n; j++){		
      scanf("%lf", &A[i][j]);
	    }
    }
 }

 void imprimeTrans(double **At,int n,int m){
  for(int i = 0; i < n; i++){
   for(int j = 0; j < m; j++){
   	printf("%.lf ", At[i][j]);
    }
   	printf("\n");
   } 
 }
 
void liberaMatriz(double **A, int m){
  for (int i = 0; i < m; i++){
    free(A[i]);
   }
  free(A);
 }

double ** transposta(double **A, int m, int n){
  double **At;
    At=criaMatriz(n, m);
	
	for(int i = 0; i < n; i++){
	  for(int j = 0; j < m; j++){
		At[i][j]=A[j][i];
	  }
	}	
	return At;	
  }

int main (){
  //declaraçao das variaveis
  int m, n;
  double **A, **At;
     
  printf("Digite o valor de m e n: "); //pedindo as dimensoes
  scanf("%d%d", &m, &n);
     
  //chamando as funçoes     
  A=criaMatriz(m, n);
   leMatriz(A, m, n);
  At=transposta( A, m, n);

  printf("Transposta:\n");
	
  imprimeTrans(At, n, m);
	
  //liberando matrizes	
  liberaMatriz(A, m);
  liberaMatriz(At, n);
	
  return 0;
}
