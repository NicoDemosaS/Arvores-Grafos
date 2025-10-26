#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

int buscarInfoRecursivo (pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if(raiz == NULL) // Provavelmente seria mais eficiente comparar com o pai, sendo maior indo pra um lado ou menor indo ao outro
        return 0;
    if(pfc(raiz->info, info)==0)
        return 1; 

    return buscarInfoRecursivo(raiz->esquerda, info, pfc) || buscarInfoRecursivo(raiz->direita, info, pfc);
}


/* ----------------------------------------------------------*/
int buscarInfo (pDArvore arvore, void *info, FuncaoComparacao pfc)
{
   return buscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif

