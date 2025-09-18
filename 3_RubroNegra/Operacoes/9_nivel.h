#ifndef NIVEL_ARVORE_BINARIA_H
#define NIVEL_ARVORE_BINARIA_H


int nivelRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao fc){
  
  if(raiz == sentinela)
    return -1;

  if(fc(info, raiz->info) == 0)
    return 0;

  int nivel_esq = nivelRecursivo(raiz->esquerda, sentinela, info, fc);
  if(nivel_esq >= 0)
      return nivel_esq + 1;
  int nivel_dir = nivelRecursivo(raiz->direita, sentinela, info, fc);
  if(nivel_dir >= 0)
      return nivel_dir + 1;

  return -1;
}


int nivel(pDArvore arvore, void *info, FuncaoComparacao fc){
  return nivelRecursivo(arvore->raiz, arvore->sentinela, info, fc);
}
#endif







