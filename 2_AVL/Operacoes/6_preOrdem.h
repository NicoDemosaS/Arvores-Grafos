#ifndef PREORDEM_ARVORE_BINARIA_H
#define PREORDEM_ARVORE_BINARIA_H

/* --------------------------*/
void preOrdemRecursiva(pNohArvore raiz, FuncaoImpressao fi){
    if (raiz != NULL){
        fi(raiz->info);
        emOrdemRecursiva(raiz->esquerda, fi);
        emOrdemRecursiva(raiz->direita, fi);
    }
    return;
}


/* --------------------------*/
void preOrdem(pDArvore arvore, FuncaoImpressao fi){
    preOrdemRecursiva(arvore->raiz, fi);
}

#endif
