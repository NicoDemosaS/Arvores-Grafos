#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

pNohArvore buscarInfoRecursivo (pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao pfc)
{
    if(raiz == sentinela) // Em Rubro-Negra usa sentinela, não NULL
        return NULL;
    if(pfc(raiz->info, info)==0)
        return raiz; 

    pNohArvore res = buscarInfoRecursivo(raiz->esquerda, sentinela, info, pfc);
    if (res) return res;
    return buscarInfoRecursivo(raiz->direita, sentinela, info, pfc);
}

/* ----------------------------------------------------------*/
pNohArvore buscarInfo (pDArvore arvore, void *info, FuncaoComparacao pfc)
{
   return buscarInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
}

#endif

