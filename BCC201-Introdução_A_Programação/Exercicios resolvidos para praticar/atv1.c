/* Questão 1 da lista de exercicios do PUCA */

#include <stdio.h>

int main(){
    int a, b, c, d, e;

    printf("Entre com 5 valores inteiros: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    if(a < b && a < c && a < d && a < e){ //verificando todos os casos que o A é menor
        printf("\n%d é o menor valor.\n", a);
    }
    else if(b < a && b < c && b < d && b < e){ // verificando B
        printf("\n%d é o menor valor.\n", b);
    }
    else if(c < a && c < b && c < d && c < e){ //verificando C
        printf("\n%d é o menor valor.\n", c);
    }
    else if(d < a && d < c && d < b && d < e){ //verificando D
        printf("\n%d é o menor valor.\n", d);
    }
    else if(e < a && e < c && e < d && e < b){ //verificando E
        printf("\n%d é o menor valor.\n", e);
    }

    return 0;
}