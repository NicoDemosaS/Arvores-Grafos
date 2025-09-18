#ifndef ancestralComum_ARVORE_BINARIA_H
#define ancestralComum_ARVORE_BINARIA_H

#include "9_nivel.h"
#include "4_buscarInfo.h"

void* ancestralComum(pDArvore arvore, void* info1, void* info2, FuncaoComparacao pfc){
    
    pNohArvore u = buscarInfo(arvore, info1, pfc);
    pNohArvore v = buscarInfo(arvore, info2, pfc);
    
    if(u == arvore->sentinela || v == arvore->sentinela)
        return NULL;

    int profU = nivel(arvore, info1, pfc);
    int profV = nivel(arvore, info2, pfc);
    
    // iguala profundidade
    while(profU > profV ) {
        u = u->pai;
        profU--;
    }
    while(profV > profU) {
        v = v->pai;
        profV--;
    }
    
    // Buscar ancestral comum
    while(u != v && u->pai != NULL && v->pai != NULL) { // faz u->pai e v->pai != null, para nao dar segmentation fault, pois as vezes chega na raiz originaria, e tenta ir ao pai, dando seg fault.
        u = u->pai;
        v = v->pai;
    }

    return u->info;
}

#endif