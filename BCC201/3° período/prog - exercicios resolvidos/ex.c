#include <stdio.h>

int main(){
    int n; 
    printf("Cálculo da Média Harmônica.\n");
    printf("Quanto numeros você quer digitar? ");
    scanf("%d", &n);

    int i = 1;
    double s = 0;
    while (i < n){
        printf("Numero %d: ", i);
        scanf("%d", &i);
        s = s + (1 / i);
        i++;
    }
    double H = n/s;
    printf("Média Harmonica: %lf\n", H);
    return 0; 
}