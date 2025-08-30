#ifndef QTDEFOLHAS_ARVORE_BINARIA_H
#define QTDEFOLHAS_ARVORE_BINARIA_H

/* -------------------------------------------*/
int quantidadeFolhasRecursiva(pNohArvore raiz){

 // caso base
 if (raiz == NULL)
    return 0;

 if (raiz->esquerda == NULL && raiz->direita == NULL)
    return 1;

 // caso recursivo
 return quantidadeFolhasRecursiva(raiz->esquerda) +
        quantidadeFolhasRecursiva(raiz->direita);

 return 0;

}

/* -------------------------------------------*/
int quantidadeFolhas(pDArvore arvore){
    return quantidadeFolhasRecursiva(arvore->raiz);
}
#endif







