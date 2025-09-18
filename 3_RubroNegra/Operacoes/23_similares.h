#ifndef similares_ARVORE_BINARIA_H
#define similares_ARVORE_BINARIA_H



int similaresRecursivas(pNohArvore raiz1, pNohArvore raiz2, pNohArvore sentinela1, pNohArvore sentinela2){
    if((raiz1 == sentinela1 && raiz2 == sentinela2))
        return 1; // SAO SIMILARES

    if((raiz1 == sentinela1 && raiz2 != sentinela2) || (raiz1 != sentinela1 && raiz2 == sentinela2))
        return 0; // NAO SAO SIMILARES

    // SE nenhum for sentinela -> busca recursiva
    return similaresRecursivas(raiz1->esquerda, raiz2->esquerda, sentinela1, sentinela2) && similaresRecursivas(raiz1->direita, raiz2->direita, sentinela1, sentinela2); 


}

int similares (pDArvore arvore1, pDArvore arvore2){
    return similaresRecursivas(arvore1->raiz, arvore2->raiz, arvore1->sentinela, arvore2->sentinela);
}

#endif







