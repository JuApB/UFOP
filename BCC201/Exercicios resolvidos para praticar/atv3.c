#include <stdio.h>
#include <math.h>

int main(){
    double x, y;

    printf("Entre com dois valores: ");
    scanf("%lf%lf", &x, &y);

    if(x == y){
        printf("Os números são iguais!\n");
    }
    else if(x < y){
        x = pow(x, 2); //quadrado do menor numero
        y = sqrt(y); //raiz quadrada do maior num

        printf("\nO quadrado do menor %.2lf e a raiz quadrada do maior %.2lf\n", x, y);
    }
    else if(y < x){
        y = pow(y, 2); //quadrado do menor numero
        x = sqrt(x); //raiz quadrada do maior num

        printf("\nO quadrado do menor %.2lf e a raiz quadrada do maior %.2lf\n", y, x);
    }

    return 0;
}