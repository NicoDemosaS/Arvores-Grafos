#ifndef NOSINTERNOS_ARVORE_BINARIA_H
#define NOSINTERNOS_ARVORE_BINARIA_H

/* --------------------------*/



int quantidadeNohsInternosRecursivo(pNohArvore raiz){
    if(raiz == NULL)
        return 0;
    if(raiz->esquerda != NULL || raiz->direita != NULL){
        // printf("CONTANDO NOH [%d]\n", *(int*)raiz->info);
        return 1 + (quantidadeNohsInternosRecursivo(raiz->direita) + quantidadeNohsInternosRecursivo(raiz->esquerda));
    }


    return 0;
}

int quantidadeNohsInternos(pDArvore arvore){
    return quantidadeNohsInternosRecursivo(arvore->raiz);
}


/* --------------------------*/


#endif
