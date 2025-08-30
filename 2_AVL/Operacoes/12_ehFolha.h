#ifndef EHFOLHA_ARVORE_BINARIA_H
#define EHFOLHA_ARVORE_BINARIA_H

/* -------------------------------------------*/
int ehFolhaRecursiva(pNohArvore raiz, void *info, FuncaoComparacao fc){

  return 0;

}

/* -------------------------------------------*/
int ehFolha(pDArvore arvore, void *info, FuncaoComparacao fc){
    return ehFolhaRecursiva(arvore->raiz, info, fc);
}
#endif







