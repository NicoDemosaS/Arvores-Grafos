#ifndef ESTRITO_ARVORE_BINARIA_H
#define ESTRITO_ARVORE_BINARIA_H




int estritamenteBinarioRecursivo(pNohArvore raiz){
    if(raiz == NULL) // ESTOU DESCONSIDERANDO QUE A ARVORE POSSA VIR NULA.
        return 1;

    if((raiz->esquerda == NULL && raiz->direita != NULL) || (raiz->direita == NULL && raiz->esquerda != NULL))
        return 0;

    

    return estritamenteBinarioRecursivo(raiz->esquerda) && estritamenteBinarioRecursivo(raiz->direita);

    
}


int estritamenteBinario(pDArvore arvore){
    return estritamenteBinarioRecursivo(arvore->raiz);

}




#endif







