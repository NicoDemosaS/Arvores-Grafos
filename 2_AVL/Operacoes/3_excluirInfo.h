#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

pNohArvore paiDaFolhaMaisEsquerda(pNohArvore raiz){

    // caso base 1
    if (raiz == NULL)
        return NULL;

    if (raiz->esquerda == NULL)
        return NULL;

    // caso base 2
    if (raiz->esquerda != NULL &&
        raiz->esquerda->esquerda == NULL)
            return raiz;

    // caso recursivo
    return paiDaFolhaMaisEsquerda(raiz->esquerda);

}


/* ------------------------------------------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc){

   // caso base 1
   if (raiz == NULL)
     return NULL;

   // caso base  2
   if (fc(raiz->info, info) == 0){   // achou

      pNohArvore filhoEsq, filhoDir;
      filhoEsq = raiz->esquerda;
      filhoDir = raiz->direita;

      free(raiz);

      // caso 1
      if (filhoEsq == NULL && filhoDir == NULL)
        return NULL;

      // caso 3
      if (filhoEsq != NULL && filhoDir != NULL){

         pNohArvore pai;
         pai = paiDaFolhaMaisEsquerda(filhoDir);

         // falta tratar esse caso
         // if(pai == NULL)
         //{

         //}

         pNohArvore folhaMaisEsquerda;
         folhaMaisEsquerda = pai->esquerda;
         pai->esquerda = folhaMaisEsquerda->direita;
         folhaMaisEsquerda->esquerda  = filhoEsq;
         folhaMaisEsquerda->direita   = filhoDir;

         return folhaMaisEsquerda;
      }
      else{
        // caso 2
        if(filhoEsq == NULL)
            return filhoDir;
        return filhoEsq;
      }

      //return NULL;
   }

   // caso recursivo
   if (fc(raiz->info, info)<0)
      raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc);
   else
      raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc);

   return raiz;
}


/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

   arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
   arvore->quantidadeNohs--;
   return 1;
}

#endif
