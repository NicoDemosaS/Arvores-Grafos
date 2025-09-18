#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H
/* --------------------------*/
pDArvore criarArvoreRubroNegra(){

    pDArvore dArvore = malloc(sizeof(DArvore));
    dArvore->quantidadeNohs = 0;

    // sentinela
    dArvore->sentinela      = malloc(sizeof(NohArvore));
    dArvore->sentinela->cor = BLACK;

    // o sentinela � a raiz da �rvore
    dArvore->raiz           = dArvore->sentinela;

    return dArvore;
};

#endif
