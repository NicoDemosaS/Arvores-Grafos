#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H

pNohArvore rotacaoDireita(pNohArvore raiz){

    pNohArvore pai = raiz->pai;

    // ajusta as cores
    raiz->esquerda->cor      = BLACK;
    raiz->cor = RED;

    // ajusta os pais
    raiz->esquerda->pai = pai;
    raiz->pai          = raiz->direita;

    pNohArvore temp = NULL;
    temp           = raiz->esquerda;
    raiz->esquerda = temp->direita;
    temp->direita  = raiz;
    return temp;
}



pNohArvore tio(pNohArvore raiz){
    if(raiz == NULL)
        return NULL;
    if (raiz->pai == NULL)
        return NULL;
    if (raiz->pai->pai == NULL)   // avo
        return NULL;

    pNohArvore avo = raiz->pai->pai;

    if(avo->esquerda == raiz->pai)
       return avo->direita;
    return avo->esquerda;
}

/* ---------------------------------------------------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao pfc, pNohArvore pai){

    // caso base
    if(raiz == sentinela){

        // incluir
        pNohArvore novo = malloc (sizeof(NohArvore));
        novo->info     = info;
        novo->esquerda = sentinela;
        novo->direita  = sentinela;
        novo->cor      = RED;

        novo->pai = pai;
        return novo;
    }

    pNohArvore filho;

    if(pfc(raiz->info, info) <= 0){

        filho = incluirInfoRecursivo(raiz->esquerda, sentinela,
                                              info, pfc, raiz);
         if (filho->direita == raiz){
            // houve rota��o a direita, n�o precisa alterar o filho esquerda,
            // somente ajusta a raiz para apontar para o filho
            raiz = filho;
         } else {
            raiz->esquerda = filho;
         }

    }
    else{
        filho = incluirInfoRecursivo(raiz->direita, sentinela,
                                              info, pfc, raiz);
        if (filho->esquerda == raiz){
           // houve rota��o a esquerda, n�o precisa alterar o filho esquerda,
           // somente ajusta a raiz para apontar para o filho
           raiz = filho;
        } else {
            raiz->direita = filho;
        }

    }

    if (raiz->cor == BLACK)
        // n�o violou nenhuma propriedade da RN
        return raiz;

    if (filho->cor == RED){
        // viola��o de propriedade
        pNohArvore titio = tio(filho);

        if (titio == NULL)
            return raiz;
        if (titio->cor == RED){
            // � suficiente recolorir
            raiz->cor     = BLACK;
            titio->cor    = BLACK;
            raiz->pai->cor = RED;
        }
        else{

            pNohArvore novaRaiz;
            printf("\n Rotacao direita %d", *((int*)raiz->info));
            novaRaiz = rotacaoDireita(raiz->pai);
            printf("\n Ap�s Rotacao direita %d", *((int*)novaRaiz->info));
            return novaRaiz;

        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    printf("\n ----------- Incluindo info: %d ---\n", *((int*)info));
    arvore->raiz = incluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc, NULL);
    arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs++;
    desenhaArvore(arvore, imprimeInt);
}

#endif

