#ifndef IGUAIS_ARVORE_BINARIA_H
#define IGUAIS_ARVORE_BINARIA_H

/* --------------------------*/


int ArvoreIguaisRecursivo(pNohArvore raiz1, pNohArvore raiz2, FuncaoComparacao fc){
    if(raiz1 == NULL && raiz2 == NULL)
        return 1;
    if(raiz1 == NULL || raiz2 == NULL)
        return 0;

    if (fc(raiz1->info, raiz2->info) != 0)
        return 0; // Informações diferentes

    // Verifica recursivamente esquerda e direita
    return ArvoreIguaisRecursivo(raiz1->esquerda, raiz2->esquerda, fc) &&
           ArvoreIguaisRecursivo(raiz1->direita, raiz2->direita, fc);
}

int ArvoreIguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc){
    ArvoreIguaisRecursivo(arvore1->raiz, arvore2->raiz, fc);

}



#endif
