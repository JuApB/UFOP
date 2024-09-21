//codigo PEDROOO
#include <stdio.h>
#include <stdlib.h>

typedef long Chave;

typedef struct {
    Chave chave;
    //outros componentes
} Registro;

typedef struct {
    Registro *v;
    int n, max;
} Dicionario;

//inicializa um dicionario
void inicioDicionario(Dicionario *dicio){
    dicio->n = 0;
    dicio->max = 10;
    dicio->v = (Registro*) malloc(sizeof(Registro)* dicio->max);
}

//encontra e retorna o índice da chave x no dicionario
int findDicionario(Dicionario *dicio, Chave c){
    int i;
    for(i =dicio->n-1; i>=0; i--){
        if(dicio->v[i].chave == c){
            return i;
        }
    }

    //retorna -1 caso a chave não seja encontrada
    return -1;
}

//insere um registro no dicionario
void insereDicionario(Dicionario *dicio, Registro *x){
    if(dicio->n == dicio->max){
        dicio->max *= 2;
        dicio->v = (Registro*) realloc(dicio->v, sizeof(Registro) * dicio->max);
    }

    //n é o tamanho
    dicio->v[dicio->n++] = x;
}

// C code to linearly search x in arr[]. - geeksforgeek

#include <stdio.h>

int search(int arr[], int N, int x)
{
	for (int i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Driver code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	int result = search(arr, N, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}
