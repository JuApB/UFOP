#include <stdio.h>
#include <math.h>

double somaN(float x, float y){
    float soma = x + y;
    return soma;
}
double produtoN(float x, float y){
    float produto = x * pow(y, 2);
    return produto;
}
double quadradoX(float x){
    float quadrado = pow(x, 2);
    return quadrado;
}
double raizN(float x, float y){
    float raiz = sqrt(pow(x, 2) + pow(y, 2));
    return raiz;
}
double moduloX(float x){
    float modulo = sqrt(pow(x, 2));
    return modulo;
}

int main (){
    float x, y;
    printf("Entre com 2 valores: ");
    scanf("%f%f", &x, &y);

    
}