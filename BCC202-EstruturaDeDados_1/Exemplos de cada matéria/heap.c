#include <stdio.h>

void heap_constroi(int *v, int n){
    int esq = (n/2)-1; //esq = primeiro nó antes do nó folha do heap
    while(esq >= 0){
        heap_refaz(v,esq,n-1);
        esq--;
    }
} 

void heap_refaz(int *v, int esq, int dir){
    int i = esq;
    int j = i*2+1;
    int aux = v[i];
    while(j <= dir){
        if(j < dir && v[j] < v[j+1]){
            j= j+1; //j recebe o outro filho de i
        }
        if(aux >= v[j]){
            break;
        }
        v[i] = v[j];
        i = j;
        j = i*2+1;
    }
    v[i] = aux;
}

void heap_sort(int *v, int n){
    heap_constroi(v, n);
    int aux;
    while(n > 1){
        aux = v[n-1];
        v[n-1] = v[0];
        n = n-1;
        heap_refaz(v, 0, n-1); //refaz o heap
    }
}

int main(){
    int *v, n;

    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }

    heap_sort(v, n);

    return 0;
}