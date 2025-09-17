#ifndef EMORDEM_ARVORE_BINARIA_H
#define EMORDEM_ARVORE_BINARIA_H

/* --------------------------*/
void emOrdemRecursiva(pNohArvore raiz, FuncaoImpressao fi){

    if (raiz != NULL){
       emOrdemRecursiva(raiz->esquerda, fi);
       fi(raiz->info);
       emOrdemRecursiva(raiz->direita, fi);
       
    }

}

/* --------------------------*/
void emOrdem(pDArvore arvore, FuncaoImpressao fi){
    emOrdemRecursiva(arvore->raiz, fi);
}

#endif
