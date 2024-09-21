/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
  
int main(){
  // Declaração das Variavéis
    int i, fibo[11];
    fibo[0] = 0;
    fibo[1] = 1;

  // Comando de repetiçao
    for(i = 2; i < 11; i++){
      fibo[i] = fibo[i-1] + fibo[i-2];
    }

  // Impressão dos 10 primeiros números da série de Fibonacci
    for(i = 1; i < 11; i++){
      printf("%d\t ", fibo[i]);
    }
    return 0;
}
