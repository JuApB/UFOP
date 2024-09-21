#include <stdio.h>
#include <stdlib.h>

void shellSort(int *v, int n){
    int h, aux, j;
    for(h = 1; h < n; h = 3*h+1);
    do{
        h = (h-1)/3;
        for(int i = h; i < n; i++){
            aux = v[i];
            j = i;
            while(v[j - h] > aux){
                v[j] = v[j-h];
                j = j-h;
                if(j < h){
                    break;
                }
            }
            v[j] = aux;
        }
    } while(h != 1);
}

int main(){
    int v[]={ 3, 4, 9, 2, 5, 1, 8, 0, 9 };
    int n = sizeof(v) / sizeof(v[0]);

    printf("\nvetor antes da ordenacao\n[");
    for (int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("]");

    shellSort(v, n);

    printf("\n\nvetor ordenado\n[");
    for (int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("]\n");


    return 0;
}