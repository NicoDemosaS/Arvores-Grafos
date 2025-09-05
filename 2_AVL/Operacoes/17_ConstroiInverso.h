#ifndef ESPELHO_ARVORE_BINARIA_H
#define ESPELHO_ARVORE_BINARIA_H


/* --------------------------*/
pNohArvore incluirInfoRecursivoInv(pNohArvore raiz, void *info, FuncaoComparacao pfc){

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

   
   // alterei o sinal para inverter a arvore ;D
   if (pfc(raiz->info, info) > 0)
       raiz->esquerda = incluirInfoRecursivoInv(raiz->esquerda, info, pfc);
   else
       raiz->direita = incluirInfoRecursivoInv(raiz->direita, info, pfc);

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
void incluirInfoInv(pDArvore arvore, void *info, FuncaoComparacao pfc){

    arvore->raiz = incluirInfoRecursivoInv(arvore->raiz, info, pfc);
}

#endif










