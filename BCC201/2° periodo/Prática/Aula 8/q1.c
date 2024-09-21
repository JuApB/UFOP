#include <stdio.h>
#include <stdlib.h>

#define TAM 30

//Criando e implementando a função
void calcMedia(float temp[], int n){
    //Declaração das Variavéis
    int abaixoMedia = 0, acimaMedia = 0;
    float media, soma = 0;
    
    for(int i = 0; i < n; i++){
        soma += temp[i];
    }
    
     //Calculando a media
    media = soma / TAM;
    
    //Cálculo - acima e abaixo da media
    for(int i = 0; i < TAM; i++){
        if(temp[i] < media)
            abaixoMedia++;
        if(temp[i] > media)
            acimaMedia++;
    }
    
    //Impressão dos valores da media, abaixo da media e acima da media
    printf("Acima: %d", acimaMedia);
    printf("\nAbaixo: %d\n", abaixoMedia);
}

int main(){
    //Declaração das Variavéis
    int n = TAM;
    float temp[TAM];
    
    //Impressão das temperaturas
    printf("\nEntre com as temperaturas: ");
    
    for(int i = 0; i < TAM; i++){
        scanf("%f", &temp[i]);
    }
    
    //Chamando a função para dentro da main
    calcMedia(temp, n);
    
    return 0;
}