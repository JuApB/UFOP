#include <stdio.h>

double calculo(float salario, int indice){
    float i, difer, novo;

    if(indice == 1){
        i = ((65.0 / 100) + 1);
        novo = (i * salario);
        printf("\nO salário atual R$ %.2f!\n\n", novo);
    }
    else if(indice == 2){
        i = ((35.0 / 100) + 1);
        novo = (i * salario);
        printf("\nO salário atual R$ %.2f!\n\n", novo);
    }
    else if(indice == 3){
        i = (12.0 / 100);
        difer = (i * salario);
        novo = (salario - difer);
        printf("\nO salário atual R$ %.2f!\n\n", novo);
    }

    return novo;
}

int main(){
    float salario;
    int indice = 0;

    printf("Entre com o salario base: ");
    scanf("%f", &salario);
    printf("\nEntre com o indice: ");
    scanf("%d", &indice);

    calculo(salario, indice);

    return 0;
}