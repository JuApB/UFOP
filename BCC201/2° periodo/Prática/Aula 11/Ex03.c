#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int *** R, int ** A, int m, int n, int ** B, int p, int q) {
    if (n == p) {
      int aux;
      for (int i = 0; i < m; i++) {
       for(int j = 0; j < q; j++) {
       aux = 0;
         for (int k = 0; k < n; k++) {
         aux += A[i][k]*B[k][j];
          }
      (*R)[i][j] = aux;
      }
    }
    return 1;
  }
    else
      return 0;
}

void imprime(int **mat, int l, int c){
    for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++){
        printf("%d ", mat[i][j]);
       }
      printf("\n");
    }
  }

void liberaMatriz(double **A, int n) {
	for(int i = 0; i < n; i++) {
	 free(A[i]);
	 }
	free(A);
}

void lerMat(int **mat, int l, int c){
    for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++) {
        scanf("%d", &mat[i][j]);
        }
      }       
  }

int **criaMatriz(int l, int c){
    int **mat;
    mat = malloc(l * sizeof(int*));
    for (int i = 0; i < l; i++)
        mat[i] = malloc(c * sizeof(int));
    return mat;
}

int main(){
  //declaraçao das variaveis
  int **A, **B, **R, m, n, p, q, v;

//matriz A
  printf("Digite os tamanhos da matriz A: ");
  scanf("%d %d", &m, &n);
  A = criaMatriz(m, n);
  printf("Digite os dados da matriz A: \n");
  lerMat(A, m, n);
    
//matriz B
  printf("\nDigite os tamanhos da matriz B: ");
  scanf("%d %d", &p, &q);
  B = criaMatriz(p, q);
  printf("Digite os dados da matriz B: \n");
  lerMat(B, p, q);

//matriz R
  R = criaMatriz(m, q);

//multiplicando a matriz
  v = multiplicaMatrizes(&R, A, m, n, B, p, q);
  if (v == 0) //verificando se não da para multiplicar
    printf("\nNão é possível multiplicar as matrizes A e B.\n");
  
  else if(v != 0){ //verificando se dá pra multiplicar
    printf("\nResultado de A x B: \n");
    imprime(R, m, q);
  }
    
    return 0; 
}