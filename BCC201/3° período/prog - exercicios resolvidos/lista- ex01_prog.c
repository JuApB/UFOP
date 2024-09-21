#include <stdio.h>

int numPares(int n){
    if(n % 2 == 0)
        printf("Numeros pares %d!\n", n);

    else
      printf("Nao é um numero par\n");

    return n;
}

int main (){
    int n;
    printf("Entre com o valor de n: \n");
    scanf("%d", &n);

    numPares(n);

    return 0;
}