#ifndef EHABB_ARVORE_BINARIA_H
#define EHABB_ARVORE_BINARIA_H

int isABBRec(pNohArvore raiz, void *min, void *max, FuncaoComparacao fc) {
    if (raiz == NULL)
        return 0;


    if ((min != NULL && fc(raiz->info, min) <= 0) ||
        (max != NULL && fc(raiz->info, max) >= 0))
        return 1;

   
    return isABBRec(raiz->esquerda, min, raiz->info, fc) &&
           isABBRec(raiz->direita, raiz->info, max, fc);
}

int isABB(pDArvore arvore, void *min, void *max, FuncaoComparacao fc) {
    return isABBRec(arvore->raiz, min, max, fc);
}

#endif







