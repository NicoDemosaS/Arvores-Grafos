#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

int buscarInfoRecursivo (pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    return 0;
}


/* ----------------------------------------------------------*/
int buscarInfo (pDArvore arvore, void *info, FuncaoComparacao pfc)
{
   return buscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif

