#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao fc){
    // Encontrar NO que eu quero
    if(raiz == sentinela)
        return sentinela;

    if(fc(raiz->info, info) == 0){  // ACHEI A INFORMACAO QUE EU QUERIA!
        if(raiz->direita != sentinela && raiz->direita->cor == RED ){  // Se filho direito eh vermelho
            printf("FILHO DIREITO EH VERMELHO!");
            if(raiz->info < raiz->pai->info) // Caso info esteja a esquerda da arvore
                raiz->pai->esquerda = raiz->direita;


            if(raiz->info > raiz->pai->info) // Caso info esteja a direita da arvore
                raiz->pai->esquerda = raiz->direita;
            
            raiz->direita->cor = BLACK; // Colore filho vermelho a preto

        } 



        if(raiz->esquerda != sentinela && raiz->esquerda->cor == RED){ // Se filho esquerdo eh vermelho
            printf("FILHO ESQUERDO EH VERMELHO!");
            if(raiz->info > raiz->pai->info) // Caso info esteja a direita da arvore
                raiz->pai->esquerda = raiz->esquerda;
            
            
            if(raiz->info < raiz->pai->info) // Caso info esteja a esquerda da arvore
                raiz->pai->esquerda = raiz->esquerda;
            
            raiz->esquerda->cor = BLACK; // Colore filho vermelho a preto


        } 
        free(raiz);
        return raiz;
    }

    excluirInfoRecursivo(raiz->esquerda, sentinela, info, fc);
    excluirInfoRecursivo(raiz->direita, sentinela, info, fc);

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    printf("\n ----------- Excluindo info: %d ---\n", *((int*)info));
    pNohArvore novaRaiz;
    novaRaiz = excluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    if (novaRaiz != NULL){
        arvore->raiz      = novaRaiz;
        arvore->raiz->cor = BLACK;
        arvore->quantidadeNohs--;
    }
    else
        printf("\n --> Chave n�o encontrada! <--");

}

#endif
