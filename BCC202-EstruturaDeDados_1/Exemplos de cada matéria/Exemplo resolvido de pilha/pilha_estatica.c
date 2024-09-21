#include "pilha.h"

void Pilha_Inicia(Pilha *pPilha){
    pPilha->tamanho = 0;
}

int Pilha_Eh_Vazia(Pilha *pPilha){
    if(pPilha->tamanho == 0)
        return 1;
    return 0;    
}

int Pilha_Push(Pilha *pPilha, Item pItem){
    if(pPilha->tamanho < MAX){
        pPilha->items[pPilha->tamanho++] = pItem;
        return 1;
    }
    return 0;
}

int Pilha_Pop(Pilha *pPilha, Item *pItem){
    if(Pilha_Eh_Vazia(pPilha)){
        return 0;
    }

    (*pItem) = pPilha->items[--pPilha->tamanho];
    return 1;
}

int Pilha_Tamanho(Pilha *){
    return pPilha->tamanho;
}

/*struct pilha{
    Item itens[MAX];
    int ultimo;
}

char* PilhaTipo(){
    return "Estatica";
}

Pilha * PilhaInicia (){
    Pilha pilha* = (Pilha*) malloc(sizeof(Pilha));
    pilha->ultimo = 0;
    return NULL;
} 

int PilhaEhVazia ( Pilha *) {
    return pPilha->ultimo == 0;
}

int PilhaPush ( Pilha *, int ){ // insere no mesmo lugar que remove 
    if(pPilha->ultimo == MAX)
      return false;
    pPilha->itens[pPilha->ultimo++] = Item;
    return true;
}

int PilhaPop ( Pilha * , int *) { // retira do mesmo lugar que insere 
    if(PilhaEhVazia(pPilha)){
        return false;
    }  
    pPilha->ultimo--;
    pItem->chave = pPilha->itens[pPilha->ultimo].chave;
    pItem->nome = pPilha->itens[pPilha->ultimo].nome;

    return true;
} 

void PilhaLibera ( Pilha **) {
    free(*pPilha);
    *pPilha= NULL;
    
}*/