#include "quicksortInterno.h"
#include "util.h"

void trocar(ItemFita *vetor, int i, int j) {
  ItemFita temp = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = temp;
}

// Particiona o vetor e retorna o indice do pivo
int particao(ItemFita *vetor, int inicio, int fim, Metrica *metrica) {
  // Escolhendo o pivo com a mediana de 3, inicio meio e fim
  int meio = (inicio + fim) / 2;

  ItemFita a = vetor[inicio];
  ItemFita b = vetor[meio];
  ItemFita c = vetor[fim];

  int indiceMediana = 0;

  metrica->comparacoes++;
  if (a.reg.nota < b.reg.nota) {
    metrica->comparacoes++;
    if (b.reg.nota < c.reg.nota) {
      indiceMediana = meio;
    } else {
      metrica->comparacoes++;
      if (a.reg.nota < c.reg.nota) {
        indiceMediana = fim;
      } else {
        indiceMediana = inicio;
      }
    }
  } else {
    metrica->comparacoes++;
    if (c.reg.nota < b.reg.nota) {
      indiceMediana = meio;
    } else {
      metrica->comparacoes++;
      if (c.reg.nota < a.reg.nota) {
        indiceMediana = fim;
      } else {
        indiceMediana = inicio;
      }
    }
  }

  // Coloca o elemento da mediana no fim
  trocar(vetor, indiceMediana, fim);

  // O pivo é o elemento final
  ItemFita pivo = vetor[fim];
  int i = inicio - 1;
  int j;

  // Varre o vetor da esquerda para a direita procurando os elementos que sao
  // menores ou iguais que o pivo.
  // esses elementos sao colocados na particao da esquerda
  for (j = inicio; j < fim; j++) {
    metrica->comparacoes++;
    if (vetor[j].reg.nota <= pivo.reg.nota) {
      i++;
      trocar(vetor, i, j);
    }
  }

  // coloca o pivo na posicao de ordenacao
  trocar(vetor, i + 1, fim);
  return i + 1; // retorna a posicao do pivo
}

// Ordena o vetor usando o quicksort
void quicksortInterno(ItemFita *vetor, int esq, int dir, Metrica *metrica) {
  if (esq < dir) {
    // Particiona o vetor e obtem o indice do pivo
    int p = particao(vetor, esq, dir, metrica);

    // Ordena os elementos antes e depois da particao
    quicksortInterno(vetor, esq, p - 1, metrica);
    quicksortInterno(vetor, p + 1, dir, metrica);
  }
}