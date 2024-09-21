//AVL
#include <stdio.h>
#include <stdlib.h>

typedef long Chave;

typedef struct {
    Chave chave;
    /* outros componentes */
} Item;

typedef struct no {
    Item item;
    struct no *pEsq;
    struct no *pDir;
} No;

typedef No *Arvore;

int FB(No *pRaiz ) {
    if ( pRaiz == NULL )
        return 0;

    return Altura ( pRaiz->pEsq )
            - Altura ( pRaiz->pDir );
 }

int Altura(No *pRaiz) {
    int iEsq , iDir;

    if ( pRaiz == NULL )
        return 0;

    iEsq = Altura (pRaiz->pEsq );
    iDir = Altura ( pRaiz->pDir );

    if ( iEsq > iDir )
        return iEsq + 1;
    else
        return iDir + 1;
}

//ROTAÇÃO SIMPLES
void RSE( No **ppRaiz) {
    No *pAux;
    pAux = (*ppRaiz)->pDir;
    (*ppRaiz)->pDir = pAux->pEsq;
    pAux->pEsq = (*ppRaiz);
    (*ppRaiz) = pAux;
}

void RSD(No **ppRaiz) {
    No *pAux;
    pAux = (*ppRaiz)->pEsq;
    (*ppRaiz)->pEsq = pAux->pDir;
    pAux->pDir = (*ppRaiz);
    (*ppRaiz) = pAux;
}

//ROTAÇÃO DUPLA
bool BalancaEsquerda(No **ppRaiz ) {
    int fbe = FB((*ppRaiz)->pEsq );
    if ( fbe >= 0 )
        RSD(ppRaiz);
    else {
        /* Rota ção Dupla Direita */
        RSE(&((*ppRaiz)->pEsq));
        RSD(ppRaiz); /* &(* ppRaiz ) */
    }
    return true;
}

int BalancaDireita(No **ppRaiz) {
    int fbd = FB((*ppRaiz)->pDir);
    if (fbd <= 0)
        RSE(ppRaiz);
    else {
        /* Rota ção Dupla Esquerda */
        RSD(&((*ppRaiz)->pDir));
        RSE(ppRaiz); /* &(* ppRaiz ) */
    }
    return true;
}

//BALANCEAMENTO
bool Balanceamento (No **ppRaiz) {
    int fb = FB(*ppRaiz);
    if (fb > 1)
        return BalancaEsquerda(ppRaiz);
    else if (fb < -1)
        return BalancaDireita(ppRaiz);
    return false;
}

//INSERÇÃO
bool Insere(No **ppRaiz, Item *x) {
    if (*ppRaiz == NULL) {
        *ppRaiz = NoCria(x);
        return true ;
    } else if((*ppRaiz)->item.chave > x->chave) {
        if (Insere(&(*ppRaiz)->pEsq,x)) {
            if (Balanceamento(ppRaiz))
                return false;
            else
                return true;
            }
    } else if ((*ppRaiz)->item.chave < x->chave) {
        if (Insere(&(*ppRaiz)->pDir,x)) {
            if (Balanceamento(ppRaiz))
                return false;
            else
                return true;
            }
    }
    return false; /* valor jah presente */
}

//REMOÇÃO
bool Remove(No **ppRaiz, Item *pX) {
    if (*ppRaiz == NULL)
        return false;
    else if ((*ppRaiz)->item.chave == pX->chave) {
        *pX = (*ppRaiz)->item;
        Antecessor(ppRaiz,&((*ppRaiz)->pEsq));
        Balanceamento(ppRaiz);
        return true;
    } else if ((*ppRaiz)->item.chave > pX->chave) {
        if (Remove(&(*ppRaiz)->pEsq, pX)) {
            Balanceamento(ppRaiz);
            return true;
        }
    } else {
        if (Remove(&(*ppRaiz)->pDir, pX)) {
            Balanceamento(ppRaiz);
            return true;
        }
    }
    return false;
}

//VERIFICA SE É UMA ARVORE AVL
bool EhArvoreAvl(No *pRaiz) {
 int fb;
 if (pRaiz == NULL)
    return true;
 if (!EhArvoreArvl(pRaiz->pEsq))
    return false;
 if (!EhArvoreArvl(pRaiz->pDir))
    return false;
 fb = FB(pRaiz);
 if ((fb > 1) || (fb < -1))
    return false;
 else
    return true;
}