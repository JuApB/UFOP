#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef int Item;

typedef struct celula{
    Item item;
    struct celula *prox;
} Celula;

typedef struct {
    Celula *cabeca;
    int tamanho;
} Pilha;

/*char* PilhaTipo();
Pilha * PilhaInicia () ;
int PilhaEhVazia ( Pilha *) ;
int PilhaPush ( Pilha *, int ); // insere no mesmo lugar que remove
/*int PilhaPop ( Pilha * , int *) ; // retira do mesmo lugar que insere 
/*void PilhaLibera ( Pilha **) ;*/

void Pilha_Inicia(Pilha *);
int Pilha_Eh_Vazia(Pilha *);
int Pilha_Push(Pilha *, Item);
int Pilha_Pop(Pilha *, Item *);
int Pilha_Tamanho(Pilha *);
void Pilha_Libera(Pilha *);

#endif