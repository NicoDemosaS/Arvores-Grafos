#ifndef ALTURA_ARVORE_BINARIA_H
#define ALTURA_ARVORE_BINARIA_H

int alturaRecursiva(pNohArvore raiz){

   if (raiz == NULL)
       return 0;

   int alturaEsq = 1 + alturaRecursiva(raiz->esquerda);
   int alturaDir = 1 + alturaRecursiva(raiz->direita);
   if (alturaEsq > alturaDir)
       return alturaEsq;

   return alturaDir;
}

int altura(pDArvore arvore){

   return alturaRecursiva(arvore->raiz) - 1;

}
#endif







