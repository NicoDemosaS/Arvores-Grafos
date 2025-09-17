#ifndef EHFOLHA_ARVORE_BINARIA_H
#define EHFOLHA_ARVORE_BINARIA_H

/* -------------------------------------------*/
int ehFolhaRecursiva(pNohArvore raiz, void *info, FuncaoComparacao fc){
  // PRA SABER SE EH FOLHA -> FILHO DIREITA NULL, FILHO ESQUERDA NULL
  if(raiz == NULL)
    return 0;

  if(fc(raiz->info, info) == 0){
    if(raiz->esquerda == NULL && raiz->direita == NULL){ // EH FOLHA!
      return 1; // ACHEI EH FOLHA!
    }
    return 0;  // ACHEI NAO EH FOLHA ;(
  }

  return ehFolhaRecursiva(raiz->esquerda, info, fc) || ehFolhaRecursiva(raiz->direita, info, fc); //busca recursiva

  return -1; // pra debugar caso ne nunca se sabe.
}

/* -------------------------------------------*/
int ehFolha(pDArvore arvore, void *info, FuncaoComparacao fc){
    return ehFolhaRecursiva(arvore->raiz, info, fc);
}
#endif







