#include <stdio.h>

int main(){
    char caractere;

    printf("Entre com um caractere: ");
    scanf("%c", &caractere);

    if((int) caractere >= 65 && caractere <= 90){
        printf("\nLetra maiuscula!\n\n");
    }
    else if((int) caractere >= 97 && caractere <= 122){
        printf("\nLetra minuscula!\n\n");
    }
    else
        printf("\nÉ um símbolo ou número!\n\n");

    return 0;    
}