#include <stdio.h>

int main(){
    float i, produto, venda, lucro;

    printf("Entre com o valor do produto: ");
    scanf("%f", &produto);

    if(produto > 20){
        i = ((45.0 / 100) + 1);
        venda = (i * produto);
        lucro = (venda - produto);
        printf("\nO valor de venda será %.2f e o lucro obtido será %.2f\n", venda, lucro);
    }
    else if(produto <= 20){
         i = ((30.0 / 100) + 1);
        venda = (i * produto);
        lucro = (venda - produto);
        printf("\nO valor de venda será %.2f e o lucro obtido será %.2f\n", venda, lucro);
    }

    return 0;
}