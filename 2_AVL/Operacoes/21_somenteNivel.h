#ifndef somenteNivel_ARVORE_BINARIA_H
#define somenteNivel_ARVORE_BINARIA_H

#include "9_nivel.h"


void somenteNivelRecursivo(pNohArvore raiz, int nivel, FuncaoImpressao pfi){
    if(raiz == NULL)
        return 0;

    if(nivel == 0)
        pfi(raiz->info);

    if(nivel > 0){
        somenteNivelRecursivo(raiz->esquerda, nivel - 1, pfi);
        somenteNivelRecursivo(raiz->direita, nivel - 1, pfi);
    }
    else
        return 0;


}


void somenteNivel(pDArvore arvore, int nivel, FuncaoImpressao pfi){
    return somenteNivelRecursivo(arvore->raiz);
}


#endif







