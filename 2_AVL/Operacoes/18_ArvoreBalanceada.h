#ifndef BALANCEADA_ARVORE_BINARIA_H
#define BALANCEADA_ARVORE_BINARIA_H


int balanceadaRecursiva(pNohArvore raiz){
    if(raiz == NULL) 
        return 0;
    if( abs(  (alturaRecursiva(raiz->esquerda)) - (alturaRecursiva(raiz->direita))  ) >= 1)
        return 1;


    return balanceadaRecursiva(raiz->esquerda) && balanceadaRecursiva(raiz->direita);
}


int balanceada(pDArvore arvore){
    return balanceadaRecursiva(arvore->raiz);

}
#endif







