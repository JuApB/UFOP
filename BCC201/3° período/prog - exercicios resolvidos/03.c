#include <stdio.h>

int main (){
    int a, b, c, d, e;
    printf("Entre com 5 valores: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    if(a < b || a < c || a < d || a < e)
        printf("Menor: %d\n", a);
    else if(b < a || b < c || b < d || b < e)
        printf("Menor: %d\n", b);
    else if(c < a || c < b || c < d || c < e)
        printf("Menor: %d\n", c);
    else if(d < a || d < b || d < c || d < e)
        printf("Menor: %d\n", d);
    else if(e < a || e < b || e < c || e < d)
        printf("Menor: %d\n", e);

    return 0;
}