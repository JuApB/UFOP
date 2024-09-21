//Dá certo com ponteiro

#include <stdio.h>

void ord3(int *a, int *b, int *c){
    int aux; 
    aux = *a;
    *a = *c;
    *c = aux;
}

int main(){
    int x = 5, y = 4, z = 3;

    ord3(&x, &y, &z);

    printf("\nValores trocados de a = %d, b = %d e c = %d\n\n", x, y, z);

    return 0;
}