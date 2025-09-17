#ifndef NIVEL_ARVORE_BINARIA_H
#define NIVEL_ARVORE_BINARIA_H


int nivelRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc){
  
  if(raiz == NULL)
    return -1;

  if(fc(info, raiz->info) == 0)
    return 0;

  int nivel_esq = nivelRecursivo(raiz->esquerda, info, fc);
  if(nivel_esq >= 0)
      return nivel_esq + 1;
  int nivel_dir = nivelRecursivo(raiz->direita, info, fc);
  if(nivel_dir >= 0)
      return nivel_dir + 1;

  return -1;
}


int nivel(pDArvore arvore, void *info, FuncaoComparacao fc){
  return nivelRecursivo(arvore->raiz, info, fc);
}
#endif







