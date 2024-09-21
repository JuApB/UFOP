#include <stdio.h>

//Implementação da funçao para ler matriz A e B
void lerMatriz(int m[10][10], int x, int y) {
    printf("\nEntre com os elementos da matriz: ");
    for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
        scanf("%d", &m[i][j]);
    }
  }
}

//Implementação da função para imprimir a matriz C
void impressaoC(int m[][10],int lin,int col){
    printf("\n");
    for(int i = 0; i < lin; i++){
      for(int j = 0; j < col; j++){
        printf("%4.d", m[i][j]);
      }
        printf("\n");
    }
 }

int main() {
  //Declaração de variáveis
  int m, p, q, n;
  int A[10][10], B[10][10], C[10][10];

  //Entrada de dados
    printf("\nEntre com os valores de m, p, q, n:");
    scanf("%d%d%d%d", &m, &p, &q, &n);

  //Verificação de valores invalidos
    while(m < 1 || m > 10 || p < 1 || p > 10 || q < 1 || q > 10 || n < 1 || n > 10 || p != q){  
      printf("\nValores inválidos! \n");
      printf("\nEntre com os valores de m, p, q, n:");
      scanf("%d%d%d%d", &m, &p, &q, &n);
    }

  //Chamada da função lerMatriz
        lerMatriz(A, m, p);
        lerMatriz(B, q, n);
  
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++) 
            C[i][j] = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  
  //Chamada da função impressaoC
  impressaoC(C, m, n);

  return 0;
}