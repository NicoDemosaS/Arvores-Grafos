#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

// Declaração antecipada para evitar warning
int alturaRecursiva(pNohArvore raiz);

pNohArvore rotacaoDireita(pNohArvore raiz){

    pNohArvore temp = NULL;
    temp           = raiz->esquerda;
    raiz->esquerda = temp->direita;
    temp->direita  = raiz;
    return temp;
}

pNohArvore rotacaoEsquerda(pNohArvore raiz){

    pNohArvore temp = NULL;
    temp            = raiz->direita;
    raiz->direita   = temp->esquerda;
    temp->esquerda  = raiz;
    return temp;
}

pNohArvore rotacaoDuplaDireita(pNohArvore raiz){
   pNohArvore novaRaiz = NULL;

   raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
   novaRaiz = rotacaoDireita(raiz);
   return novaRaiz;
}

pNohArvore rotacaoDuplaEsquerda(pNohArvore raiz){
   pNohArvore novaRaiz = NULL;

   raiz->direita = rotacaoDireita(raiz->direita);
   novaRaiz = rotacaoEsquerda(raiz);
   return novaRaiz;
}



void recalcularFatorBalanceamento(pNohArvore raiz){
   if(raiz == NULL)
    return;

   raiz->fator = alturaRecursiva(raiz->direita) -
                 alturaRecursiva(raiz->esquerda);

   recalcularFatorBalanceamento(raiz->esquerda);
   recalcularFatorBalanceamento(raiz->direita);

}

/* --------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

   // caso base
   if (raiz == NULL){

    pNohArvore novo = malloc(sizeof(NohArvore));
    novo->info = info;
    novo->esquerda = NULL;
    novo->direita  = NULL;
    novo->fator    = 0;

    return novo;
   }
   // caso recursivo
   if (pfc(raiz->info, info) < 0)
       raiz->esquerda = incluirInfoRecursivo(raiz->esquerda, info, pfc);
   else
       raiz->direita = incluirInfoRecursivo(raiz->direita, info, pfc);

   // recalcular o fator de balanceamento da raiz
   raiz->fator = alturaRecursiva(raiz->direita) -
                 alturaRecursiva(raiz->esquerda);

   printf("\nFator: %d", raiz->fator);

   if (raiz->fator == 2 || raiz->fator == -2){
       pNohArvore novaRaiz;

       printf("\nPrecisa rotacionar!!!!");

       if(raiz->fator == 2){

            if (raiz->direita->fator >= 0)
               novaRaiz = rotacaoEsquerda(raiz);
            else
                novaRaiz = rotacaoDuplaEsquerda(raiz);
       }

       if (raiz->fator == -2){
            if(raiz->esquerda->fator <= 0)
               novaRaiz = rotacaoDireita(raiz);
            else
               novaRaiz = rotacaoDuplaDireita(raiz);
       }

       // observe que o recalculo do fator � a partir da
       // nova raiz, pois a raiz anterior virou filho da
       // nova raiz
       recalcularFatorBalanceamento(novaRaiz);
       return novaRaiz;

   }

  return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif

