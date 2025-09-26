#ifndef EXCLUIRINFO_BTREE_H
#define EXCLUIRINFO_BTREE_H

/* --------------------------*/
pNohBTree excluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave, FuncaoComparacao pfc){

   if (raiz == NULL) 
       return NULL;

   int i;
   int qtde = raiz->listaChavesValores->quantidade;

   // procurar chave no no atual
   for (i = 1; i <= qtde; i++){
       pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i);

       int cmp = pfc(pcv, chave);

       if (cmp == 0){
           // chave encontrada
           if (ehFolha(raiz)){
               // caso 1: chave em folha → remove direto
               excluirInfoPos(raiz->listaChavesValores, i);
           } else {
               // caso 2: chave em nó interno
              
               pNohBTree filho = pcv->filhoMaior;
               while (filho && filho->primeiroFilho != NULL)
                   filho = filho->primeiroFilho;

               pChaveValor substituto = buscarInfoPos(filho->listaChavesValores, 1);
               pcv->chave = substituto->chave;
               pcv->valor = substituto->valor;

               // excluir chave do filho
               excluirInfoBTreeRecursivo(filho, ordem, substituto->chave, pfc);
           }
           break;
       }

       if (cmp < 0){
           // chave pode estar na subárvore esquerda de pcv
           if (i == 1)
               raiz->primeiroFilho = excluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, pfc);
           else {
               pChaveValor ant = buscarInfoPos(raiz->listaChavesValores, i-1);
               ant->filhoMaior = excluirInfoBTreeRecursivo(ant->filhoMaior, ordem, chave, pfc);
           }
           break;
       }

       if (i == qtde){
           // chave pode estar na subárvore direita do último
           pcv->filhoMaior = excluirInfoBTreeRecursivo(pcv->filhoMaior, ordem, chave, pfc);
           break;
       }
   }

   // ajuste: se raiz ficou sem chaves
   if (raiz->listaChavesValores->quantidade == 0){
       if (raiz->primeiroFilho != NULL){
           pNohBTree novaRaiz = raiz->primeiroFilho;
           novaRaiz->pai = NULL;
           free(raiz);
           return novaRaiz;
       }
   }

   return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc){

     pNohBTree novaRaiz = excluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, pfc);
     if (novaRaiz == NULL){
        printf(" -->> Erro! Chave informada n�o existe na �rvore!!! <<--");
     }
     else{
        arvore->raiz = novaRaiz;
     }

    return 1;

}

#endif

