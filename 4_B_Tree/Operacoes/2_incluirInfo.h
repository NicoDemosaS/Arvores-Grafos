#ifndef INCLUIR_INFO_BTREE_H
#define INCLUIR_INFO_BTREE_H

//---------------------------------
int comparaChaveValor(void *info1, void *info2){
    pChaveValor  p1 = (pChaveValor) info1;
    pChaveValor  p2 = (pChaveValor) info2;
    return *((int*)(p2->chave)) - *((int*)(p1->chave));
}

//---------------------------------
pNohBTree criarNohBTree(){

    pNohBTree pNovo           = malloc(sizeof(NohBTree));

    pNovo->primeiroFilho      = NULL;
    pNovo->listaChavesValores = criarLista();
    pNovo->pai                = NULL;

    return pNovo;
}

//---------------------------------
ChaveValor* criarChaveValor(void* chave, void* valor, pNohBTree filhoMaior){

    ChaveValor* pcv = malloc(sizeof(struct chaveValor));
    pcv->chave      = chave;
    pcv->valor      = valor;
    pcv->filhoMaior = filhoMaior;
    return pcv;
}

/* --------------------------*/
int ehFolha(pNohBTree raiz){

   if(raiz == NULL)
      return 0;

   if(raiz->primeiroFilho != NULL)
      return 0;

   int i=1;
   while (i <= raiz->listaChavesValores->quantidade){

        pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i);

        if(pcv->filhoMaior != NULL)
           return 0;

        i++;
    }
    // eh folha, retorna 1 [true]
    return 1;
}

/* --------------------------*/
pChaveValor chaveAnterior(pDLista lista, void* chave, FuncaoComparacao pfc){

    pNoh atual = lista->primeiro;
    pNoh ant   = NULL;

    while (atual != NULL){
       pChaveValor pcv = (pChaveValor) atual->info;
       if(pfc(pcv->chave, chave) < 0){
           if (ant != NULL)
             return ant->info;

           return NULL;
       }

        ant   = atual;
        atual = atual->prox;
    }
    return ant->info;
}

/* --------------------------*/
pNohBTree incluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void* chave, void* valor, FuncaoComparacao pfc){

   // caso base 1 - árvore não tem raiz
   if (raiz == NULL){

        pNohBTree novo = criarNohBTree();
        pChaveValor novaChaveValor = criarChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(novo->listaChavesValores, novaChaveValor, comparaChaveValor);
        return novo;
   }

   pNohBTree novaRaiz = raiz;

   // caso baso 2 - a raiz é uma folha
   if(ehFolha(raiz) == 1){

       // precisa verificar se a chave já está na folha
       int result = contemInfo(raiz->listaChavesValores, chave, pfc);
       if(result !=0){
          // achou a chave, aborta a inclusão
          return NULL;
       }

       pChaveValor novaChaveValor = criarChaveValor(chave, valor, NULL);
       incluirInfoOrdenada(raiz->listaChavesValores, novaChaveValor, comparaChaveValor);
   } else {

      // caso recursivo
      int qtdeChaves = raiz->listaChavesValores->quantidade;
      int cont;
      pChaveValor pcvAnt;
      pChaveValor pcv;

      for(cont = 1; cont <= qtdeChaves; cont++){

          pcv = buscarInfoPos(raiz->listaChavesValores, cont);

          int busca = pfc(pcv, chave);
            //printf(" --> Resultado da busca da chave: %d <--", busca);
          if(busca == 0){
             // achou a chave, n o precisa fazer nada
             printf(" --> achou a chave <--");
             return NULL;
          }

          if (busca < 0 && cont == 1){
             novaRaiz = incluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, valor,pfc);
             break;
          }

          if (busca < 0  && cont > 1 && cont <= qtdeChaves){
             novaRaiz = incluirInfoBTreeRecursivo(pcvAnt->filhoMaior, ordem, chave, valor,pfc);
             break;
          }

          if (cont == qtdeChaves){
             novaRaiz = incluirInfoBTreeRecursivo(pcv->filhoMaior, ordem, chave, valor,pfc);
             break;
          }

          pcvAnt = pcv;
      }
}

   // verifica se a chave foi encontrada na árvore - novaRaiz == NULL
   if(novaRaiz == NULL)
      return NULL;

   // após a inclusão da chave na árvore, verifica se a folha que recebeu a chave
   // não violou a regra de conter no máximo 2d chaves
   if (raiz->listaChavesValores->quantidade > ordem*2){

      pNohBTree novoNoh           = criarNohBTree();
      novoNoh->listaChavesValores = dividirLista(raiz->listaChavesValores, ordem);

      pNohBTree pai;
      // Entrada d+1 sobe para o pai
      if(raiz->pai == NULL){
         // cria um novo noh que ser  a raiz da  rvore
         pai                = criarNohBTree();
         pai->primeiroFilho = raiz;
         raiz->pai          = pai;
      }
      else{
         pai = raiz->pai;
      }

      pChaveValor mediano         = excluirInfoPos(novoNoh->listaChavesValores, 1);
      incluirInfoOrdenada(pai->listaChavesValores, mediano, comparaChaveValor);

      novoNoh->primeiroFilho = mediano->filhoMaior;
      mediano->filhoMaior     = novoNoh;

      return pai;
   }

   // ao final, retorna a nova raiz
   if (novaRaiz->pai == NULL)
       return novaRaiz;

   return novaRaiz->pai;
}

/* ----------------------------------------------------------*/
int incluirInfoBTree(pDBTree arvore, void *chave, void *valor, FuncaoComparacao pfc){

     desenhaArvore(arvore, imprimeInt);
     printf("\n ---> Incluindo ....: %d [ ", *((int*)chave));

     pNohBTree novaRaiz = incluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
     if (novaRaiz == NULL){
        printf(" -->> Erro! Chave informada já existe na árvore!!! <<--");
     }
     else{
        arvore->raiz = novaRaiz;
     }

     printf(" ] \n\n");
     return 1;
}

#endif

