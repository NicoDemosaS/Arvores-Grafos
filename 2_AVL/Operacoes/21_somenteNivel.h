#ifndef somenteNivel_ARVORE_BINARIA_H
#define somenteNivel_ARVORE_BINARIA_H


void somenteNivelRecursivo(pNohArvore raiz, int nivel, FuncaoImpressao pfi){
    if(raiz == NULL)
        return;
    
    if(nivel == 0)
        pfi(raiz->info);

    if(nivel > 0){
        somenteNivelRecursivo(raiz->esquerda, nivel - 1, pfi);
        somenteNivelRecursivo(raiz->direita, nivel - 1, pfi);
    }

}

void somenteNivel(pDArvore arvore, int nivel, FuncaoImpressao pfi){
    return somenteNivelRecursivo(arvore->raiz, nivel, pfi);
}


#endif







