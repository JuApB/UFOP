#include <stdio.h>

int menor_maior(int n1, int n2, int n3, int menor, int maior){
    int meio;
    if(n1 > n2 && n2 < n3){
        menor = n2;
        maior = n1;
        meio = n3;
        return 1;
    }
    else if(n2 > n3 && n3 < n1){
        menor = n3;
        maior = n2;
        meio = n1;
        return 1;
    }
    else if(n3 > n1 && n1 < n2){
        menor = n1;
        maior = n3;
        meio = n2;
        return 1;
    }
    else 
      return 0;
}

int main(){
    int n1, n2, n3, maior, menor, meio;
    printf("Digite três números reais: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    int ret = menor_maior(n1, n2, n3, menor, maior);

    if(ret == 1){
      printf("\nMenor número: %d", menor);
      printf("\nMaior número: %d", maior);
      printf("\n\nLogo: %d <= %d <= %d\n", menor, meio, maior);
    }

    return 0;
}