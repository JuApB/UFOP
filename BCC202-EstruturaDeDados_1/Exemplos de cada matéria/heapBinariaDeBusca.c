#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long Chave ;

typedef struct {
    /* outros componentes */
    Chave chave ;
} Item ;

typedef struct no {
    Item item ;
    struct no * pEsq ;
    struct no * pDir ;
} No ;

typedef No * Arvore ;

void Arvore_Inicia(No **pRaiz) {
    *pRaiz = NULL;
}

//Função Pesquisa RECURSIVA pela árvore
bool ArvorePesquisa(No *pRaiz, Chave c, Item *pX){
    if(pRaiz == NULL)
        return false;

    if(c < pRaiz->item.chave)
        return ArvorePesquisa(pRaiz->pEsq, c, pX);
    if(c > pRaiz->item.chave)
        return ArvorePesquisa(pRaiz->pDir, c, pX);

    *pX = pRaiz->item;
    return true;
}

//Função Pesquisa ITERATIVA pela árvore
bool ArvorePesquisa(No *pRaiz, chave c, Item *pX){
    No *pAux;

    pAux = pRaiz;
    while(pAux != NULL){
        if(c == pAux->item.chave){
            *pX = pAux->item;
            return true;
        }
        else if(c > pAux->item.chave){
            pAux = pAux->pDir;
        }
        else
            pAux = pAux->pEsq;
    }
    return false; //não encontrado!
}

//Função cria um nó
No* NoCria(Item x) {
    No* pAux = (No*) malloc(sizeof(No));
    pAux -> item = x;
    pAux -> pEsq = NULL ;
    pAux -> pDir = NULL ;
    return pAux ;
}

//Função Inserção RECURSIVA na árvore
bool ArvoreInsere(No** ppR, Item x){
    if (*ppR == NULL) {
        *ppR = NoCria(x);
        return true ;
    }

    if (x.chave < (*ppR)->item.chave)
        return ArvoreInsere(&((* ppR)->pEsq), x);
    if (x.chave > (*ppR)->item.chave)
        return ArvoreInsere(&((* ppR)->pDir), x);

    return false ; // elemento jah existe
}

//Funções RECURSIVA na árvore V2 (sem ponteiro de ponteiro)
void ArvoreInsereRaiz (No **ppRaiz, Item x ) {
    if (*ppRaiz == NULL) {
    *ppRaiz = NoCria(x);
    return;
    }
    ArvoreInsere(*ppRaiz, x);
}

bool ArvoreInsere (No *pRaiz, Item x) {
    // arvore vazia
    if (pRaiz == NULL) return false;
    if (x.chave < pRaiz->item.chave) {
        if (pRaiz->pEsq == NULL) {
            pRaiz->pEsq = NoCria(x);
            return true;
            }
        return ArvoreInsere(pRaiz->pEsq, x);
    }
    if (x.chave > pRaiz->item.chave) {
        if (pRaiz->pDir == NULL) {
            pRaiz->pDir = NoCria(x);
            return true;
            }
        return ArvoreInsere(pRaiz->pDir, x);
    }

    return false; // elemento jah existe
}

//Função Inserção ITERATIVA na árvore
bool ArvoreInsere (No **ppRaiz, Item x) {
    No **ppAux;
    ppAux = ppRaiz;

    while (*ppAux != NULL) {
        if (x.chave < (*ppAux)->item.chave)
            ppAux = &((*ppAux)->pEsq);
        else if (x.chave > (*ppAux)->item.chave)
            ppAux = &((*ppAux)->pDir);
        else
            return false;
    }
    *ppAux = NoCria(x);
    return true;
}

//Função Remoção RECURSIVA de um nó da árvore
void ArvoreSucessor(No *q, No **r) {
    No *pAux;
    if((*r)->pEsq != NULL) {
        ArvoreSucessor(q, &(*r)->pEsq);
        return;
    }
    q->item = (*r)->item;
    pAux = *r;
    *r = (*r)->pDir;
    free(pAux);
}

bool ArvoreRetira(No **p, Item x) {
    No *pAux;
    if (*p == NULL)
        return false;

    if (x.chave < (*p)->item.chave)
        return ArvoreRetira(&((*p)->pEsq), x);

    if (x.chave > (*p)->item.chave)
        return ArvoreRetira(&((*p)->pDir), x);

    if ((*p)->pEsq == NULL && (*p)->pDir == NULL) { // no eh folha
        free(*p);
        *p = NULL;
        return true;
    }


    if ((*p)->pEsq != NULL && (*p)->pDir == NULL) { // esq
        pAux = *p;
        *p = (*p)->pEsq;
        free(pAux);
        return true;
    }
    if ((*p)->pDir != NULL && (*p)->pEsq == NULL) { // dir
        pAux = *p;
        *p = (*p)->pDir;
        free(pAux);
        return true;
    }

    // no possui dois filhos
    // Pode -se usar tamb ém ArvoreAntecessor (*p, &((* p) ->pEsq ));
    ArvoreSucessor(*p, &((*p)->pDir));

    return true;
}
