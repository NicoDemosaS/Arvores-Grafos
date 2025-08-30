#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvore criarArvoreAVL(){

    pDArvore desc = malloc(sizeof(pDArvore));
    desc->raiz           = NULL;
    desc->quantidadeNohs = 0;

    return desc;
};

#endif
