#ifndef QTDENOHS_ARVORE_BINARIA_H
#define QTDENOHS_ARVORE_BINARIA_H

/* -------------------------------------------*/
int quantidadeNohsRecursiva(pNohArvore raiz){

  // caso base
  if (raiz == NULL)
    return 0;

  // caso recursivo
  return 1 + quantidadeNohsRecursiva(raiz->esquerda) +
             quantidadeNohsRecursiva(raiz->direita);

}

/* -------------------------------------------*/
int quantidadeNohs(pDArvore arvore){
    return quantidadeNohsRecursiva(arvore->raiz);
}
#endif







