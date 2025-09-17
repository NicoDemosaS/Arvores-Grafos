#ifndef umfilho_ARVORE_BINARIA_H
#define umfilho_ARVORE_BINARIA_H

// Fazer busca recursiva
// Verificar se o no tem somente filho da esquerda OU somente filho da direita
// Caso sim, adicionar 1 em alguma soma
// em algum momento retornar essa soma, depois de percorrer toda a arvore?

int UmFilhoRecursivo(pNohArvore raiz){ 
    if(raiz == NULL)
        return 0;

    if((raiz->esquerda == NULL && raiz->direita != NULL) || (raiz->direita == NULL && raiz->esquerda != NULL)){ // VERIFICANDO SE TEM SOMENTE UM FILHO
        return 1 + UmFilhoRecursivo(raiz->direita) + UmFilhoRecursivo(raiz->esquerda);
    }
    else
        return UmFilhoRecursivo(raiz->esquerda) + UmFilhoRecursivo(raiz->direita);

}

int filhoUnico (pDArvore arvore){
    return UmFilhoRecursivo(arvore->raiz);
}

#endif







