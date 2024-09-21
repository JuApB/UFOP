// C code to implement quicksort

#include <stdio.h>

// Função para trocar dois elementos
void trocar(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// Particionar o array usando o último elemento como pivô
int particao(int v[], int baixo, int alto)
{
	// Escolhendo o pivô
	int pivo = v[alto];

	// Índice de elemento menor e indica
	// a posição correta do pivô encontrada até agora
	int i = (baixo - 1);

	for (int j = baixo; j <= alto - 1; j++) {

		// Se o elemento atual for menor que o pivô
		if (v[j] < pivo) {

			// Índice de incremento do elemento menor
			i++;
			trocar(&v[i], &v[j]);
		}
	}
	trocar(&v[i + 1], &v[alto]);
	return (i + 1);
}

// A função principal que implementa o QuickSort
// v[] --> Matriz a ser classificada,
// baixo --> Índice inicial,
// alto --> índice final
void quickSort(int v[], int baixo, int alto)
{
	if (baixo < alto) {

		// pi é o índice de particionamento, v[p]
		// agora está no lugar certo
		int pi = particao(v, baixo, alto);

        // Classifique os elementos separadamente antes
        // partição e depois da partição
		quickSort(v, baixo, pi - 1);
		quickSort(v, pi + 1, alto);
	}
}

// Código do motorista
int main()
{
	int v[] = { 10, 7, 8, 9, 1, 5, 0, 47, 92 };
	int N = sizeof(v) / sizeof(v[0]);

	// Function call
	quickSort(v, 0, N - 1);
	printf("Matriz ordenada: \n");
	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);

    printf("\n");
	return 0;
}



// Escolhendo o pivô
	/*Pacote pivot = pacotes[r];

	// Índice de elemento menor e indica
	// a posição correta do pivô encontrada até agora
	int i = (p - 1);

	for (int j = p; j <= r - 1; j++) {

		// Se o elemento atual for menor que o pivô
		if (pacotes[j] < pivot) {

			// Índice de incremento do elemento menor
			i++;
			swap(&pacotes[i], &pacotes[j]);
		}
	}
	swap(&pacotes[i + 1], &pacotes[r]);
	return (i + 1);*/
