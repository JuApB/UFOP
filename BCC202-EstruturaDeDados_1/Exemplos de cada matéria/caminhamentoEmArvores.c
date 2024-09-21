void PreOrdem (No *p) {
    if (p == NULL)
        return;
    printf("%ld\n", p->item.chave);
    PreOrdem(p->pEsq);
    PreOrdem(p->pDir);
}

void PosOrdem(No *p) {
    if (p == NULL)
        return;
    PosOrdem(p->pEsq);
    PosOrdem(p->pDir);
    printf("%ld\n", p->item.chave) ;
}

void Central(No *p) {
    if (p == NULL)
        return;
    Central(p->pEsq);
    printf("%ld\n", p->item.chave);
    Central(p->pDir);
}