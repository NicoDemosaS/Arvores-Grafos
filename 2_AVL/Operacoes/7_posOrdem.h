#ifndef POSORDEM_ARVORE_BINARIA_H
#define POSORDEM_ARVORE_BINARIA_H


/* --------------------------*/
void posOrdemRecursiva(pNohArvore raiz, FuncaoImpressao fi){
    if(raiz != NULL){
        posOrdemRecursiva(raiz->esquerda, fi);
        posOrdemRecursiva(raiz->direita, fi);
        fi(raiz->info);
    }
}

/* --------------------------*/
void posOrdem(pDArvore arvore, FuncaoImpressao fi){
    return posOrdemRecursiva(arvore->raiz, fi);
}

#endif





